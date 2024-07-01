
include(../../CPlatform.txt)

set(PROJECT_NAME socket)

################################################################################
# Source groups
################################################################################

set(Source
    src/auxiliar.c
    src/buffer.c
    src/buffer.c
    src/compat.c
    src/except.c
    src/inet.c
    src/io.c
    src/luasocket.c
    src/options.c
    src/select.c
    src/tcp.c
    src/timeout.c
    src/udp.c
    src/wsocket.c
)
source_group("Source" FILES ${Source})

set(ALL_FILES
    ${Source}
)

ADD_DEFINITIONS(-D_WINSOCK_DEPRECATED_NO_WARNINGS)

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

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug>:"
            "ws2_32;"
        ">"
        "$<$<CONFIG:Release>:"
            "ws2_32;"
        ">"
        "$<$<CONFIG:Editor_Debug>:"
            "ws2_32;"
        ">"
        "$<$<CONFIG:Editor_Release>:"
            "ws2_32;"
        ">"
    )
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

################################################################################
# Compile and link options
################################################################################
include(../../VSCompileLink.txt)
