#pragma once

#include "../System/System.h"
#include "Meta/json.h"

NS_JYE_BEGIN

namespace Reflection
{
    class META_API TypeMetaRegister
    {
    public:
        static void metaRegister();
        static void metaUnregister();
    };
} // namespace Reflection

NS_JYE_END