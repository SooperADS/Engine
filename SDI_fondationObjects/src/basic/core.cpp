#include "SDI/libCore.h"
#include "SDI/Basic/Types.h"

struct init2 { SDI_DLL_API bool isInit(); };
bool init2::isInit()
{ return true; }

HINSTANCE SDI::Libs::LibCoreInit::GetHandle() const
{ return *SDI::Libs::CoreGlobalVars::StartCoreDLLHandle; }

void SDI::Libs::LibCoreInit::Empty()
{ SDI::Libs::LibCore_GlobalVars->ToZero(); }

bool SDI::Libs::LibCoreInit::IsLoad() const
{ return SDI::Libs::LibCore_GlobalVars; }

template<class ptrType>
bool SDI::Libs::LibCoreInit::Init(ptrType ptr)
{	if (ptr) return true;

	try{if (!ptr)
		{	bool r;
			init2 i; init2* ip = new init2{};
			r = (i.isInit() && ip->isInit());

			ptr->ToDefault();

			return r; } }
	catch (...)	{ return false; } }

void SDI::Libs::CoreGlobalVars::ToDefault()
{
	/* Позже сделаю */
}

void SDI::Libs::CoreGlobalVars::ToZero()
{
	/* Позже сделаю */
}

const HINSTANCE* SDI::Libs::LibCore_GetHandle()
{ return SDI::Libs::LibCore_GlobalVars->StartCoreDLLHandle; }

void SDI::Libs::LibCore_Empty()
{	SDI::Libs::LibCore_GlobalVars->LibINIT.Empty();
	delete SDI::Libs::LibCore_GlobalVars; }

bool SDI::Libs::LibCore_isLoad()
{ return SDI::Libs::LibCore_GlobalVars->LibINIT.IsLoad(); }

bool SDI::Libs::LibCore_Init()
{
	SDI::Libs::LibCore_GlobalVars = new CoreGlobalVars{};

	SDI::Libs::LibCoreInit l;
	return l.Init(SDI::Libs::LibCore_GlobalVars);
}

SDI::Libs::CoreGlobalVars* SDI::Libs::LibCore_GlobalVars;

HINSTANCE* SDI::Libs::CoreGlobalVars::StartCoreDLLHandle = nullptr;
SDI::Libs::LibCoreInit SDI::Libs::CoreGlobalVars::LibINIT{};
