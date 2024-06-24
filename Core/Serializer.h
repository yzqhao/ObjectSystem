#pragma once
#include "Meta/json.h"
#include "Meta/reflection.h"
#include "Object.h"

#include <cassert>
#include <unordered_map>
#include <unordered_set>

NS_JYE_BEGIN

static const std::string gRefStr = "RefObject";

class CORE_API Serializer
{
public:
    template<typename T>
    static Json writePointer(T* instance)
    {
        return Json::object {{"$typeName", Json {"*"}}, {"$context", Serializer::write(*instance)}};
    }

    template<typename T>
    static T*& readPointer(const Json& json_context, T*& instance)
    {
        assert(instance == nullptr);
        std::string type_name = json_context["$typeName"].string_value();
        assert(!type_name.empty());
        if ('*' == type_name[0])
        {
            instance = new T;
            read(json_context["$context"], *instance);
        }
        else
        {
            instance = static_cast<T*>(
                Reflection::TypeMeta::newFromNameAndJson(type_name, json_context["$context"]).m_instance);
        }
        return instance;
    }

    template<typename T>
    static Json write(const Reflection::ReflectionPtr<T>& instance)
    {
        T*          instance_ptr = static_cast<T*>(instance.operator->());
        std::string type_name    = instance.getTypeName();
        return Json::object {{"$typeName", Json(type_name)},
                                {"$context", Reflection::TypeMeta::writeByName(type_name, instance_ptr)}};
    }

    template<typename T>
    static T*& read(const Json& json_context, Reflection::ReflectionPtr<T>& instance)
    {
        std::string type_name = json_context["$typeName"].string_value();
        instance.setTypeName(type_name);
        return readPointer(json_context, instance.getPtrReference());
    }

    template<typename T>
    static Json write(const T& instance)
    {
		if constexpr (TIsEObjectPointerType<T>::Value)
		{
			Object* Temp = (Object*)(void*)instance;
			m_objectArray.push_back(Temp);
			return Json(gRefStr + std::to_string(m_objectArray.size()));
		}
		else if constexpr (TIsEObjectSmartPointerType<T>::Value)
		{
			Pointer<Object>& Temp = *(Pointer<Object>*)(void*) & instance;
			m_objectArray.push_back(Temp.GetEObject());
			return Json(gRefStr + std::to_string(m_objectArray.size()));
		}
        else if constexpr (std::is_pointer<T>::value)   
        {
            return writePointer((T)instance);
        }
		else if constexpr (std::is_enum<T>::value)
		{
			return write((int)instance);
		}
        else
        {
            return Json();
        }
    }

    template<typename T>
    static T& read(const Json& json_context, T& instance)
    {
        if constexpr (std::is_pointer<T>::value)
        {
            return readPointer(json_context, instance);
        }
        else
        {
            return instance;
        }
    }

	template<typename T>
    static Json SerializerObject(const T& instance)
    {
        Json::object res;
		Json jo = write(instance);
		res.insert_or_assign("Root", jo);

        std::unordered_set<Object*> allOjbect;
        for (int i = 0; i < m_objectArray.size(); ++i)
        {
            if (allOjbect.count(m_objectArray[i]) == 0)
            {
                allOjbect.insert(m_objectArray[i]);
                res.insert_or_assign(std::to_string(i), write(*((*m_objectArray[i]).REAL_TYPE*)(m_objectArray[i])));
            }
        }
        return Json(res);
    }

private:
    static uint32_t m_version;
    static std::vector<Object*> m_objectArray;
};

// implementation of base types
template<>
CORE_API Json Serializer::write(const char& instance);
template<>
CORE_API char& Serializer::read(const Json& json_context, char& instance);

template<>
CORE_API Json Serializer::write(const int& instance);
template<>
CORE_API int& Serializer::read(const Json& json_context, int& instance);

template<>
CORE_API Json Serializer::write(const unsigned int& instance);
template<>
CORE_API unsigned int& Serializer::read(const Json& json_context, unsigned int& instance);

template<>
CORE_API Json Serializer::write(const float& instance);
template<>
CORE_API float& Serializer::read(const Json& json_context, float& instance);

template<>
CORE_API Json Serializer::write(const double& instance);
template<>
CORE_API double& Serializer::read(const Json& json_context, double& instance);

template<>
CORE_API Json Serializer::write(const bool& instance);
template<>
CORE_API bool& Serializer::read(const Json& json_context, bool& instance);

template<>
CORE_API Json Serializer::write(const std::string& instance);
template<>
CORE_API std::string& Serializer::read(const Json& json_context, std::string& instance);

NS_JYE_END
