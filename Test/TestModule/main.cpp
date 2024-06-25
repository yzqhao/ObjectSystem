#include "TestObject.h"
#include "../../Engine/object/Scene.h"
#include "Engine/reflection_register.h"
#include "Engine/AssetManager.h"
#include "Engine/component/CameraComponent.h"
#include "Engine/component/ParticleComponent.h"
#include "Engine/object/GameObject.h"

USING_JYE_CC


int main()
{
    Main::Initialize();

    Reflection::TypeMetaRegister::metaRegister();

	Scene* s = new Scene("NewScene");
    s->CreateObject("a");
    GameObject* partGO = s->CreateObject("c");
    ParticleComponent* partcom = partGO->CreateComponent<ParticleComponent>();
    partcom->AddEvolver(ParticleProperty::Ev_Rotation);
    partcom->AddEvolver(ParticleProperty::Ev_Size);

    AssetManager::SaveAsset(*s, "testSave.json");

    Reflection::TypeMetaRegister::metaUnregister();

    Main::Terminate();

	return 0;
}