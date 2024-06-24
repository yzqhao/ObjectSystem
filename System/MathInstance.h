#pragma once
#include "Macros.h"

NS_JYE_BEGIN

class SYSTEM_API MathInstance
{
public:
	float GetFastSin(unsigned int i);
	float GetFastCos(unsigned int i);
	uint CRC32Compute(const void* pData, uint uiDataSize);
	uint CRC32Compute(const void* InData, int Length, uint CRC);
	static MathInstance& GetMathInstance()
	{
		static MathInstance g_MathInitial;
		return g_MathInitial;
	}
protected:
	MathInstance();

	void VSInitCRCTable();
	float FastSin[361];
	float FastCos[361];
	unsigned int CRCTable[256];
};

NS_JYE_END