# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
include(../CPlatform.txt)

set(PROJECT_NAME Math)

################################################################################
# Source groups
################################################################################
set(Source
    "3DMath.h"
    "AABB.cpp"
    "AABB.h"
    "Mat3.cpp"
    "Mat3.h"
    "Mat4.cpp"
    "Mat4.h"
    "Math.cpp"
    "Math.h"
    "MathUtil.cpp"
    "MathUtil.h"
	"MathUtil.inl"
    "Plane.cpp"
    "Plane.h"
    "Quaternion.cpp"
    "Quaternion.h"
    "Ray.cpp"
    "Ray.h"
    "Rect.cpp"
    "Rect.h"
    "Sphere.cpp"
    "Sphere.h"
    "Vec1.cpp"
    "Vec2.h"
    "Vec2.cpp"
    "Vec2.h"
    "Vec3.cpp"
    "Vec3.h"
    "Vec4.cpp"
    "Vec4.h"
)
source_group("Source" FILES ${Source})

set(ALL_FILES
    ${Source}
)

add_compile_definitions (
    MATH_EXPORTS
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
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
	System
    Meta
	)
target_link_libraries(${PROJECT_NAME} PUBLIC
    System
    Meta
)	

################################################################################
# Compile and link options
################################################################################
include(../VSCompileLink.txt)


### precompile
# set global vari used by precompile
file(GLOB_RECURSE HEADER_FILES "*.h")
set(MATH_HEADS "${HEADER_FILES}" PARENT_SCOPE)
#MESSAGE("-----------------============================------------------: " ${HEADER_FILES})

file(GLOB_RECURSE ENGINE_HEADER_FILES "${ROOT_PATH}/Engine/*.h")
set(ENGINE_HEADS "${ENGINE_HEADER_FILES}" PARENT_SCOPE)
#MESSAGE("-----------------============================------------------: " ${ENGINE_HEADER_FILES})

