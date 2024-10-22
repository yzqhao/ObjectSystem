# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
include(../CPlatform.txt)

set(PROJECT_NAME Engine)

set(ENGINE_ROOT_DIR ${ROOT_PATH}/Engine/)

################################################################################
# Source groups
################################################################################

set(__private
    "private/Define.h"
    "private/Define.cpp"
)
source_group("private" FILES ${__private})

set(__object
    "object/GameObject.h"
    "object/GameObject.cpp"
    "object/Scene.h"
    "object/Scene.cpp"
)
source_group("object" FILES ${__object})

set(__component
    "component/Animatable.h"
    "component/Animatable.cpp"
    "component/Component.h"
    "component/Component.cpp"
    "component/CameraComponent.h"
    "component/CameraComponent.cpp"
    "component/LightComponent.h"
    "component/LightComponent.cpp"
    "component/RenderComponent.h"
    "component/RenderComponent.cpp"
    "component/TransformComponent.h"
    "component/TransformComponent.cpp"
    "component/ParticleProperty.h"
    "component/ParticleEvolver.h"
    "component/ParticleEvolver.cpp"
    "component/ParticleComponent.h"
    "component/ParticleComponent.cpp"
    "component/ScriptComponent.h"
    "component/ScriptComponent.cpp"
)
source_group("component" FILES ${__component})

set(Source
    "reflection_register.h"
    "reflection_register.cpp"
    "AssetManager.h"
    "AssetManager.cpp"
)
source_group("Source" FILES ${Source})

set(ALL_FILES
    ${__private}
    ${__object}
    ${__component}
    ${Source}
)

add_compile_definitions (
    ENGINE_EXPORTS
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${ROOT_PATH}/bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_EDITOR_DEBUG ${ROOT_PATH}/bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${ROOT_PATH}/bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_EDITOR_RELEASE ${ROOT_PATH}/bin/)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} ${LIBRARY_TYPE_BY_PLATFORM} ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Engine")

################################################################################
# PreParser
################################################################################
### precompile
# set global vari used by precompile

set(CODEGEN_TARGET "PreCompile")
include(precompile/precompile.cmake)
set_target_properties("${CODEGEN_TARGET}" PROPERTIES FOLDER "Engine" )

add_dependencies("${CODEGEN_TARGET}" "Parser")
	
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Any CPU")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG          "${PROJECT_NAME}_d"
        TARGET_NAME_EDITOR_DEBUG   "${PROJECT_NAME}_d"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG          "${PROJECT_NAME}_d"
        TARGET_NAME_EDITOR_DEBUG   "${PROJECT_NAME}_d"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG          "${PROJECT_NAME}_d"
        TARGET_NAME_EDITOR_DEBUG   "${PROJECT_NAME}_d"
    )
endif()

################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PRIVATE
    "${ROOT_PATH}/Third/rapidjson/include"
	"${ROOT_PATH}"
)

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
	Core
	)
target_link_libraries(${PROJECT_NAME} PUBLIC
    Core
)	

################################################################################
# Compile and link options
################################################################################
include(../VSCompileLink.txt)
	