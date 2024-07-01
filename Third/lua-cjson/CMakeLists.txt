# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
include(../../CPlatform.txt)

set(PROJECT_NAME luacjson)

################################################################################
# Source groups
################################################################################

set(Headers
    "define.h"
    "fpconv.h"
    "strbuf.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "fpconv.c"
    "lua_cjson.c"
    "strbuf.c"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Headers}
    ${Sources}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${ROOT_PATH}/bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_EDITOR_DEBUG ${ROOT_PATH}/bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${ROOT_PATH}/bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_EDITOR_RELEASE ${ROOT_PATH}/bin/)

################################################################################
# Target
################################################################################
set(CMAKE_DEBUG_POSTFIX "")
set(CMAKE_EDITOR_DEBUG_POSTFIX "")

add_library(${PROJECT_NAME} ${LIBRARY_TYPE_BY_PLATFORM} ${ALL_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Third/Script")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "cjson")

################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Any CPU")
    target_include_directories(${PROJECT_NAME} PRIVATE
        "${ROOT_PATH}/Third/LuaJIT-2.1/src"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
    target_include_directories(${PROJECT_NAME} PRIVATE
        "${ROOT_PATH}/Third/LuaJIT-2.1/src"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PRIVATE
        "${ROOT_PATH}/Third/LuaJIT-2.1/src"
    )
endif()

################################################################################
# Dependencies
################################################################################

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug>:"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/buildvm.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/lua51.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/luajit.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/minilua.lib;"
        ">"
        "$<$<CONFIG:Editor_Debug>:"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/buildvm.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/lua51.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/luajit.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/minilua.lib;"
        ">"
        "$<$<CONFIG:Editor_Release>:"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/buildvm.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/lua51.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/luajit.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/minilua.lib;"
        ">"
        "$<$<CONFIG:Release>:"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/buildvm.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/lua51.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/luajit.lib;"
            "${ROOT_PATH}/Third/LuaJIT-2.1/prebuild/windows/x64/minilua.lib;"
        ">"
    )
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")	

################################################################################
# Compile and link options
################################################################################
include(../../VSCompileLink.txt)
