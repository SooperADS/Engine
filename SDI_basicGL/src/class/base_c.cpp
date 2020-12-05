#include "SDI/Graphics/GLCore.h"

struct init2 { __declspec(dllexport) bool isInit(); };

HINSTANCE SDI::Libs::LibGLInit::GetHandle() const
{ return *SDI::Libs::LibGL_GlobalVars->StartCoreDLLHandle; }

void SDI::Libs::LibGLInit::Empty()
{ SDI::Libs::LibGL_GlobalVars->ToZero(); }

bool SDI::Libs::LibGLInit::IsLoad() const
{ return SDI::Libs::LibGL_GlobalVars; }

template<class ptrType>
bool SDI::Libs::LibGLInit::Init(ptrType ptr)
{	if (ptr) return true;

	try{if (!ptr)
		{	bool r;
			r = SDI::Libs::LibGL_Init();
			init2 i; init2* ip = new init2{};
			r = (i.isInit() && ip->isInit() && r);

			ptr->ToDefault();

			return r; }	}
	catch (...) { return false; } }

void SDI::Libs::GraphicsGlobalVars::ToDefault()
{
	/* Позже сделаю */
}

void SDI::Libs::GraphicsGlobalVars::ToZero()
{
	/* Позже сделаю */
}

const HINSTANCE* SDI::Libs::LibGL_GetHandle()
{ return SDI::Libs::LibGL_GlobalVars->StartCoreDLLHandle; }

void SDI::Libs::LibGL_Empty()
{	SDI::Libs::LibGL_GlobalVars->LibINIT.Empty();
	delete SDI::Libs::LibGL_GlobalVars; }

bool SDI::Libs::LibGL_isLoad()
{ return SDI::Libs::LibGL_GlobalVars->LibINIT.IsLoad(); }

bool SDI::Libs::LibGL_Init()
{	SDI::Libs::LibGL_GlobalVars = new GraphicsGlobalVars{};

	SDI::Libs::LibGLInit l;
	return l.Init(SDI::Libs::LibGL_GlobalVars); }

HINSTANCE* SDI::Libs::GraphicsGlobalVars::StartCoreDLLHandle;
SDI::Libs::LibGLInit SDI::Libs::GraphicsGlobalVars::LibINIT;

SDI::Libs::GraphicsGlobalVars* SDI::Libs::LibGL_GlobalVars;
