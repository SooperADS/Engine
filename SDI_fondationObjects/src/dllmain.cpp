#include "framework.h"
#include "SDI/libCore.h"

#include <mutex>

//import link
BOOL APIENTRY DllMain( HMODULE hModule,
					   DWORD  ul_reason_for_call,
					   LPVOID lpReserved )
{	std::mutex* mt = nullptr;
	
	switch (ul_reason_for_call) {
		// Process start
	case DLL_THREAD_ATTACH:
		mt = new std::mutex;
		mt->lock();
	case DLL_PROCESS_ATTACH:
		if (!SDI::Libs::LibCore_Init())
		{	SDI::Libs::LibCore_Empty();
			return FALSE; }

		SDI::Libs::LibCore_GlobalVars->StartCoreDLLHandle = &hModule;
		break;

		// Process end
	case DLL_THREAD_DETACH:
		delete mt;
		mt = nullptr;
	case DLL_PROCESS_DETACH:
		SDI::Libs::LibCore_GlobalVars->StartCoreDLLHandle = nullptr;
		SDI::Libs::LibCore_Empty();
		break;

	default:
		return FALSE;
		break;
	}

	return TRUE; }
