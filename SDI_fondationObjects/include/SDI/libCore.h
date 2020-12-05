// Enter the "#define SDI_DLL_IMPORT" 
// before connecting this file to connect this library

#ifdef SDI_IMPORT_OK
	#ifndef SDI_END_IMPORT_OK
		#define SDI_END_IMPORT_OK
		#pragma warning(pop)
	#endif // !SDI_END_IMPORT_OK
#endif

#ifndef SDI_libCoreLibHeader_incleder
#define SDI_libCoreLibHeader_incleder
#pragma once

//			Macross								Default		Values

#ifndef SDI_OPTION_disableBuilderWarnings
	#define SDI_OPTION_disableBuilderWarnings	1			// YES/NO
#endif // !SDI_OPTION_disableBuilderWarnings

#ifndef SDI_OPTION_disableLinkerWarnings
	#define SDI_OPTION_disableLinkerWarnings	1			// YES/NO
#endif // !SDI_OPTION_disableBuilderWarnings

#ifndef SDI_OPTION_disableOtherWarnings
	#define SDI_OPTION_disableOtherWarnings		1			// YES/NO
#endif // !SDI_OPTION_disableBuilderWarnings

#ifndef SDI_OPTION_buildErrorLevel
	#define SDI_OPTION_buildErrorLevel			4			// 0 - 5
#endif // !SDI_OPTION_disableBuilderWarnings

#ifndef SDI_OPTION_messangeBoxError
	#define SDI_OPTION_messangeBoxError			2			// YES(2) / DEBUG_ONLY(1) / NO(0)
#endif // !SDI_OPTION_disableBuilderWarnings

#define staticOption constexpr static

#pragma warning(push)
#if SDI_OPTION_disableBuilderWarnings
	#pragma warning ( disable : 4668 5039 4273 4365 4820  )
#endif

#if SDI_OPTION_disableLinkerWarnings
	#pragma warning ( disable :  )
#endif

#if SDI_OPTION_disableOtherWarnings
	#pragma warning ( disable : 4710 4820 5039 )
#endif

	#if (SDI_DLL_IMPORT || SDI_DLL_GL_IMPORT || SD_DLL_CORE_IMPORT)
		#define SDI_DLL_IMPORTSTATUS 0
	#else
		#define SDI_DLL_IMPORTSTATUS 1
	#endif // SDI_DYNAMIC_LIB_IMPORT || SDI_DLL_IMPORT

#ifndef SDI_DLL_API
	#if (SDI_DLL_IMPORT || SD_DLL_CORE_IMPORT)
		#define SDI_DLL_API __declspec(dllexport)
		#define SDI_DLL_API_H extern __declspec(dllexport)
		#define SDI_DLL_API_T __declspec(dllexport)
		#define SDI_DLL_API_C __declspec(dllexport)
	#else
		#define SDI_DLL_API __declspec(dllimport)
		#define SDI_DLL_API_H extern __declspec(dllimport)
		#define SDI_DLL_API_T extern __declspec(dllimport)
		#define SDI_DLL_API_C
	#endif
#endif // !SDI_DLL_API

#ifndef SDI_GL_DLL_API
	#if (SDI_DLL_IMPORT || SD_DLL_GL_IMPORT)
		#define SDI_GL_DLL_API __declspec(dllexport)
		#define SDI_GL_DLL_API_H extern __declspec(dllexport)
		#define SDI_GL_DLL_API_T __declspec(dllexport)
		#define SDI_GL_DLL_API_C __declspec(dllexport)
	#else
		#define SDI_GL_DLL_API __declspec(dllimport)
		#define SDI_GL_DLL_API_H extern __declspec(dllimport)
		#define SDI_GL_DLL_API_T extern __declspec(dllimport)
		#define SDI_GL_DLL_API_C
	#endif
#endif // !SDI_DLL_API

#ifdef _WIN32
	#ifndef _WIN64
		#define _WINBIT_VALUE 32
		#define _WINBIT_STATE 1
	#else
		#define _WINBIT_VALUE 64
		#define _WINBIT_STATE 2
	#endif // _WIN32
#else
	#define _WINBIT_VALUE 0
	#define _WINBIT_STATE 0
#endif // !_WIN64

#ifdef _DEBUG
	#define _CONFIG_NAME "Debug"
	#define _CONFIG_ID 1
#elif defined(_RELEASE)
	#define _CONFIG_NAME "Release"
	#define _CONFIG_ID 2
#elif defined(_LIB_DEBUG)
	#define _CONFIG_NAME "Lib_Debug"
	#define _CONFIG_ID 3
#else
	#define _CONFIG_NAME "Unknown"
	#define _CONFIG_ID 0
#endif

#ifndef NULL
#define NULL 0
#endif // !NULL

#ifndef NULLBODY
#define NULLBODY {}
#endif // !NULL

#define startPointAPI(handle, handle64, cmdline, cmdshow)	\
INT WINAPI WinMain(	_In_		HINSTANCE	handle,			\
					_In_opt_	HINSTANCE	handle64,		\
					_In_		LPSTR		cmdline,		\
					_In_		INT			cmdshow)

#include <windows.h>

namespace SDI
{
	namespace Libs
	{
		class CoreGlobalVars;

		__interface INITType
		{	virtual HINSTANCE GetHandle() const = 0;
			virtual void Empty() = 0;
			virtual bool IsLoad() const = 0; };
		__interface GlobalVars
		{	virtual void ToDefault() = 0;
			virtual void ToZero() = 0; };

		struct LibCoreInit : public INITType
		{	SDI_DLL_API HINSTANCE GetHandle() const override;
			SDI_DLL_API void Empty() override;
			SDI_DLL_API bool IsLoad() const override;

			template<class ptrType>
			inline bool Init(ptrType ptr); };
		class CoreGlobalVars : public GlobalVars
		{ public:		static SDI_DLL_API_C HINSTANCE* StartCoreDLLHandle;
						static SDI_DLL_API_C LibCoreInit LibINIT;

						SDI_DLL_API void ToDefault() override;
						SDI_DLL_API void ToZero() override;	};

		SDI_DLL_API_H CoreGlobalVars* LibCore_GlobalVars;

		SDI_DLL_API_H const HINSTANCE* LibCore_GetHandle();
		SDI_DLL_API_H void LibCore_Empty();
		SDI_DLL_API_H bool LibCore_isLoad();
		SDI_DLL_API_H bool LibCore_Init();
	}
}

#define SDI_IMPORT_OK
#endif //SDI_libCoreLibHeader_incleder
