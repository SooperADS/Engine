#pragma once

#ifndef SDI_libGraphicsCoreLibHeader_incleder
#define SDI_libGraphicsCoreLibHeader_incleder

#include "SDI/libCore.h"
namespace SDI
{
	namespace Libs
	{
		struct LibGLInit : public INITType
		{	SDI_GL_DLL_API HINSTANCE GetHandle() const override;
			SDI_GL_DLL_API void Empty() override;
			SDI_GL_DLL_API bool IsLoad() const override;

			template<class ptrType>
			bool Init(ptrType ptr); };

		class GraphicsGlobalVars : public GlobalVars
		{ public:	static HINSTANCE* StartCoreDLLHandle;
					static LibGLInit LibINIT;

					SDI_GL_DLL_API void ToDefault() override;
					SDI_GL_DLL_API void ToZero() override;};

		SDI_GL_DLL_API_H GraphicsGlobalVars* LibGL_GlobalVars;

		SDI_GL_DLL_API_H const HINSTANCE* LibGL_GetHandle();
		SDI_GL_DLL_API_H void LibGL_Empty();
		SDI_GL_DLL_API_H bool LibGL_isLoad();
		SDI_GL_DLL_API_H bool LibGL_Init();
	}
}

#endif