#pragma once
#include "../Third/json11/json11.hpp"
using Json = json11::Json;

#ifdef _PLATFORM_WINDOWS
#ifdef META_EXPORTS
    #define META_API     __declspec(dllexport)
#else
    #define META_API     __declspec(dllimport)
#endif
#else
    #define META_API
#endif