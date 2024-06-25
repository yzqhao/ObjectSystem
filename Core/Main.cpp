
#include "Main.h"
#include "RttiManager.h"

NS_JYE_BEGIN

std::vector<Main::Element>* Main::ms_pInitialArray = NULL;
std::vector<Main::Element>* Main::ms_pTerminalArray = NULL;

void Main::AddInitialFunction(Function Func)
{
	if (!Func)
		return;
	if (!ms_pInitialArray)
	{
		ms_pInitialArray = _NEW std::vector<Element>;
	}
	Element e;
	e.Func = Func;
	ms_pInitialArray->push_back(e);
}

void Main::AddTerminalFunction(Function Func)
{
	if (!Func)
		return;
	if (!ms_pTerminalArray)
	{
		ms_pTerminalArray = _NEW std::vector<Element>;
	}
	Element e;
	e.Func = Func;
	ms_pTerminalArray->push_back(e);
}

bool Main::Initialize()
{
	RttiManager::Instance()->Initlize();

    //std::sort(ms_pInitialArray->begin(), ms_pInitialArray->end(), PriorityCompare());
	for (unsigned int i = 0; i < ms_pInitialArray->size(); i++)
	{
		if (!(*((*ms_pInitialArray)[i].Func))())
		{
			JY_ASSERT(0);
			return false;
		}
	}

	ms_pInitialArray->clear();
	SAFE_DELETE(ms_pInitialArray);

	return true;
}

bool Main::Terminate()
{
	//std::sort(ms_pTerminalArray->begin(), ms_pTerminalArray->end(), PriorityCompare());
	if (ms_pTerminalArray)
	{
        for (int i = ms_pTerminalArray->size() - 1; i >= 0; i--)
        {
            if (!(*((*ms_pTerminalArray)[i].Func))())
            {
                JY_ASSERT(0);
                return false;
            }
        }

        ms_pTerminalArray->clear();
        SAFE_DELETE(ms_pTerminalArray);
	}

	RttiManager::Instance()->Destory();

	return true;
}


NS_JYE_END

