#include "Serializer.h"
#include <assert.h>

NS_JYE_BEGIN

uint32_t Serializer::m_version = 1;
Serializer::SerInner Serializer::m_innerSer;
Serializer::DeSerInner Serializer::m_innerDeSer;

template<>
Json Serializer::write(const char& instance)
{
	return Json(instance);
}
template<>
char& Serializer::read(const Json& json_context, char& instance)
{
	assert(json_context.is_number());
	return instance = json_context.number_value();
}

template<>
Json Serializer::write(const int& instance)
{
	return Json(instance);
}
template<>
int& Serializer::read(const Json& json_context, int& instance)
{
	assert(json_context.is_number());
	return instance = static_cast<int>(json_context.number_value());
}

template<>
Json Serializer::write(const unsigned int& instance)
{
	return Json(static_cast<int>(instance));
}
template<>
unsigned int& Serializer::read(const Json& json_context, unsigned int& instance)
{
	assert(json_context.is_number());
	return instance = static_cast<unsigned int>(json_context.number_value());
}

template<>
Json Serializer::write(const int64& instance)
{
    return Json(instance);
}
template<>
int64& Serializer::read(const Json& json_context, int64& instance)
{
    assert(json_context.is_number());
    return instance = static_cast<int64>(json_context.number_value());
}

template<>
Json Serializer::write(const uint64& instance)
{
    return Json((int64)instance);
}
template<>
uint64& Serializer::read(const Json& json_context, uint64& instance)
{
    assert(json_context.is_number());
    return instance = static_cast<int64>(json_context.number_value());
}

template<>
Json Serializer::write(const float& instance)
{
	return Json(instance);
}
template<>
float& Serializer::read(const Json& json_context, float& instance)
{
	assert(json_context.is_number());
	return instance = static_cast<float>(json_context.number_value());
}

template<>
Json Serializer::write(const double& instance)
{
	return Json(instance);
}
template<>
double& Serializer::read(const Json& json_context, double& instance)
{
	assert(json_context.is_number());
	return instance = static_cast<float>(json_context.number_value());
}

template<>
Json Serializer::write(const bool& instance)
{
	return Json(instance);
}
template<>
bool& Serializer::read(const Json& json_context, bool& instance)
{
	assert(json_context.is_bool());
	return instance = json_context.bool_value();
}

template<>
Json Serializer::write(const std::string& instance)
{
	return Json(instance);
}
template<>
std::string& Serializer::read(const Json& json_context, std::string& instance)
{
	assert(json_context.is_string());
	return instance = json_context.string_value();
}

// -----------------------------------------------------------------------------------

void Serializer::SerInner::Clear()
{
	m_objectArray.clear();
	m_serState.clear();
	m_serJsons.clear();
}

bool Serializer::SerInner::RegisterObject(Object* pObject)
{
	JY_ASSERT(pObject);

    for (uint i = 0; i < (uint)m_objectArray.size(); i++)
    {
        if (m_objectArray[i] == pObject)
        {
            return false;
        }
    }
    m_objectArray.push_back((Object*)pObject);

    return true;
}

int Serializer::SerInner::GetObjectLinkID(Object* pObject)
{
    for (int i = 0; i < (int)m_objectArray.size(); i++)
    {
        if (m_objectArray[i] == pObject)
        {
            return i;
        }
    }
	return -1;
}

bool Serializer::SerInner::IsFinishObject(Object* pObject)
{
	return m_serState.count(pObject) > 0;
}

void Serializer::SerInner::BeginSerializer(Object* pObject)
{
	m_serState.insert(pObject);
}

void Serializer::SerInner::SetObjectSerializer(Object* pObject, Json context)
{
	JY_ASSERT(m_serJsons.count(pObject) == 0);
	Json::object& jsonObj = (Json::object&)context.object_items();
	jsonObj.insert_or_assign(gRttiStr, (int)pObject->GetTypeID());
	m_serJsons[pObject] = context;
}

void Serializer::SerInner::SerializerAllObject(Json::object& outContext)
{
	JY_ASSERT(m_serJsons.size() == m_objectArray.size());
	Json::array m_children_json;
    for (auto& item : m_objectArray) {
        m_children_json.emplace_back(m_serJsons[item]);
    }
	outContext.insert_or_assign("objects", m_children_json);
}

// -----------------------------------------------------------------------------------

void Serializer::DeSerInner::Clear()
{

}

void Serializer::DeSerInner::InitObjectContext(Json::array& objArray)
{
    m_objectArray.resize(objArray.size());
    m_objects.resize(objArray.size());
    for (int i = 0; i < objArray.size(); ++i)
        m_objects[i] = &objArray[i];
}

Object* Serializer::DeSerInner::GetRegisterObject(int idx)
{
	return m_objectArray[idx];
}

void Serializer::DeSerInner::RegisterObject(Object* pObject, int idx)
{
    JY_ASSERT(pObject);
	m_objectArray[idx] = pObject;
}

Json* Serializer::DeSerInner::GetJson(int idx)
{
    return m_objects[idx];
}

NS_JYE_END