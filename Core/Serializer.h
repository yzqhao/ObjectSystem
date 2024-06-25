#pragma once
#include "Meta/json.h"
#include "Meta/reflection.h"
#include "Type.h"
#include "Object.h"

NS_JYE_BEGIN

static const std::string gRefStr = "RefObject";

class CORE_API Serializer
{
private:
    class CORE_API SerInner
    {
    public:
        void Clear();
        bool RegisterObject(Object* pObject);
        int GetObjectLinkID(Object* pObject);
        bool IsFinishObject(Object* pObject);
        void BeginSerializer(Object* pObject);
        void SetObjectSerializer(Object* pObject, Json context);
        void SerializerAllObject(Json::object& outContext);
    public:
        std::unordered_map<Object*, Json> m_serJsons;
        std::unordered_set<Object*> m_serState;
        std::vector<Object*> m_objectArray;
    };
public:
    template<typename T>
    static void RegisterObjectPointer(const T* instance)
    {
        Register(*instance);
    }

    template<typename T>
    static void Register(T* instance)
    {
        if (TIsEObjectPointerType<T*>::Value)
        {
            Object* Temp = (Object*)instance;
            if (Temp && m_inner.RegisterObject(Temp))
            {
                RegisterObjectPointer(instance);
            }
        }
    }

    template<typename T>
    static void Register(const T& instance)
    {
    }

    template<typename T>
    static Json writeObjectPointer(const T* instance)
    {
        return write(*instance);
    }

    template<typename T>
    static Json writePointer(const T* instance)
    {
        if (TIsEObjectType<T>::Value)
        {
            // TODO
            Object* Temp = *(Object**)&instance;
            if (!m_inner.IsFinishObject(Temp))
            {
                m_inner.BeginSerializer(Temp);
                m_inner.SetObjectSerializer(Temp, writeObjectPointer(instance));
            }
            return Json::object{ {"$typeName", Json {"*"}}, {"$gRefStr", Serializer::write(m_inner.GetObjectLinkID(Temp))} };;
        }
        else if (std::is_pod<T>::value)
        {
            return Json::object{ {"$typeName", Json {"*"}}, {"$context", Serializer::write(*instance)} };;
        }
        else
        {
            JY_ASSERT(false);
        }
    }

    template<typename T>
    static T*& readPointer(const Json& json_context, T*& instance)
    {
        assert(instance == nullptr);
        std::string type_name = json_context["$typeName"].string_value();
        assert(!type_name.empty());
        if ('*' == type_name[0])
        {
            instance = nullptr;//new T;
            read(json_context["$context"], *instance);
        }
        else
        {
            JY_ASSERT(false);
        }
        return instance;
    }

    template<typename T>
    static Json write(const T& instance)
    {
        if constexpr (std::is_pointer<T>::value)
        {
            if ((T)instance != nullptr)
                return writePointer((T)instance);
        }
        else if (std::is_enum<T>::value)
        {
            return write<int>(instance);
        }
        else
        {
            JY_ASSERT(false);
        }
        return Json();
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

public:
    Serializer();
    ~Serializer();

    template<typename T>
    Json SerializerObject(const T& instance)
    {
        Object* tempObj = (Object*)&instance;

        m_inner.RegisterObject(tempObj);  //×¢²á×Ô¼º
        Register(instance);

        m_inner.BeginSerializer(tempObj);
        m_inner.SetObjectSerializer(tempObj, write(instance));

        Json::object  retContext;
        retContext.insert_or_assign("version", Serializer::write(m_version));
        m_inner.SerializerAllObject(retContext);
        return Json(retContext);
    }

private:
    static uint32_t m_version;
    static SerInner m_inner;
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
CORE_API Json Serializer::write(const int64& instance);
template<>
CORE_API int64& Serializer::read(const Json& json_context, int64& instance);

template<>
CORE_API Json Serializer::write(const uint64& instance);
template<>
CORE_API uint64& Serializer::read(const Json& json_context, uint64& instance);

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
