
#pragma once

#include "Macros.h"
#include "TypeHash.h"
#include "Macros.h"

NS_JYE_BEGIN

inline void* Memset(void* pDest, int iC, USIZE_TYPE uiCount)
{
	return memset(pDest, iC, uiCount);
}

inline void* Memcpy(void* pDest, const void* pSrc, USIZE_TYPE uiCount)
{
	return memcpy(pDest, pSrc, uiCount);
}

inline bool Memcmp(const void* buf1, const void* buf2, USIZE_TYPE uiCount)
{
	return memcmp(buf1, buf2, uiCount);
}

static inline void* Memzero(void* Dest, USIZE_TYPE Count)
{
	return memset(Dest, 0, Count);;
}

template< class T >
static inline void Memzero(T& Src)
{
	Memzero(&Src, sizeof(T));
}

inline unsigned int SizeTypeToGUID32(USIZE_TYPE Size_Type)
{
	return (Size_Type & 0xffffffff);
}

inline USIZE_TYPE GUID32ToSizeType(unsigned int uiGUID)
{
#ifdef PLATFORM_WIN32
#if _WIN64
	return (uiGUID & 0x00000000ffffffff);
#else
	return (uiGUID & 0xffffffff);
#endif
#else
    return (uiGUID & 0x00000000ffffffff);
#endif
}

inline int ComparePointer(void* Point1, void* Point2)
{
	if (((USIZE_TYPE)Point1) == ((USIZE_TYPE)Point2))
	{
		return 0;
	}
	else if (((USIZE_TYPE)Point1) > ((USIZE_TYPE)Point2))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

struct LogCategory
{
	LogCategory(const std::string& name) { sTagName = (name); }
	std::string sTagName;
};

#define DECLARE_LOG_TAG(CategoryName) \
	extern struct FLogCategory##CategoryName : public LogCategory \
	{ \
		FLogCategory##CategoryName() : LogCategory((#CategoryName)) {} \
	} CategoryName;

#define DEFINE_LOG_TAG(CategoryName) FLogCategory##CategoryName CategoryName;

NS_JYE_END
