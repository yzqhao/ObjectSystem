# Install script for directory: C:/Users/haojingyu/source/repos/ObjectSystem

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/ObjectSystem")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/system_dir/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/meta_dir/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/math_dir/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/core_dir/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/test_testmodule_dir/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/lua_dir/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/luasocket_dir/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/lua_cjson_dir/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/lua_bit_dir/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/luafilesystem_dir/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/json11_lib/cmake_install.cmake")
  include("C:/Users/haojingyu/source/repos/ObjectSystem/buiild/meta_parser_dir/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/haojingyu/source/repos/ObjectSystem/buiild/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
