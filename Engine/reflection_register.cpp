#include <assert.h>

#include "reflection_register.h"

#include "Meta/reflection.h"
#include "Core/serializer.h"

#include "_generated/reflection/all_reflection.h"
#include "_generated/serializer/all_serializer.ipp"

NS_JYE_BEGIN

namespace Reflection
{
    void TypeMetaRegister::metaUnregister() { TypeMetaRegisterinterface::unregisterAll(); }
} // namespace Reflection

NS_JYE_END
