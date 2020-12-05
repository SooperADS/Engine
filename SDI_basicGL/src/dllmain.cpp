#include "framework.h"
#include <mutex>

#pragma warning ( disable : 26819 4100 )

// Точка входа при инжектировании
BOOL WINAPI DllMain( HMODULE	hModule,
					 DWORD		ul_reason_for_call,
					 LPVOID		lpReserved )
{	std::mutex* mt = nullptr;

	switch (ul_reason_for_call) {
	// Process start
	case DLL_THREAD_ATTACH:
		mt = new std::mutex;
		mt->lock();
	case DLL_PROCESS_ATTACH:
		if (!SDI::Libs::LibGL_Init())
		{	SDI::Libs::LibGL_Empty();
			return FALSE; }
		SDI::Libs::LibGL_GlobalVars->StartCoreDLLHandle = &hModule;
		break;

	// Process end
	case DLL_THREAD_DETACH:
		delete mt;
		mt = nullptr;
	case DLL_PROCESS_DETACH:
		SDI::Libs::LibGL_GlobalVars->StartCoreDLLHandle = nullptr;
		SDI::Libs::LibGL_Empty();
		break;
	
	default:
		return FALSE;
		break; }

	return TRUE; }
