#ifndef SDI_libWinAPICoreS0_incleder

#include <windows.h>

#include "SDI/libCore.h"
#include "Messange.h"

namespace SDI
{
	namespace WinAPI
	{	
		SDI_GL_DLL_API_H void registrHandle(HINSTANCE h);
		inline HINSTANCE startIdeProcess = 0;

		/*LRESULT __stdcall defautWindWork(HWND, UINT, WPARAM, LPARAM)
		{ return 0; }*/

		template<typename handleType>
		class basicWinAPIObject
		{ protected:	handleType handleBase = NULL;

		public:			virtual handleType getHandle() const = 0;
						virtual handleType* getPointer() = 0; };

		class basicWindow 
		: public basicWinAPIObject<HWND>
		{ protected:	WNDCLASSEX winProp;

		public:			staticOption WNDPROC defaultMassangeWorkr = NULL;
			
						struct windHandles 
						{	HICON hIcon;
							HICON hIconMini;
							HCURSOR hCursor;
							HBRUSH hbrBack;
							HINSTANCE hInst; };
			
						SDI_GL_DLL_API basicWindow();
						SDI_GL_DLL_API basicWindow(const basicWindow& obj);
						SDI_GL_DLL_API basicWindow(basicWindow* obj);

						SDI_GL_DLL_API basicWindow( const UINT style, 
													const WNDPROC function,
													const windHandles handles,
													const LPCTSTR className,
													const LPCTSTR menuName)
						{	this->winProp.cbSize = sizeof(this->winProp);
							this->winProp.cbWndExtra = 0;
							this->winProp.cbClsExtra = 0;
							this->winProp.lpfnWndProc = function;
							this->winProp.hbrBackground = handles.hbrBack;
							this->winProp.hCursor = handles.hCursor;
							this->winProp.hIcon = handles.hIcon;
							this->winProp.hIconSm = handles.hIconMini;
							this->winProp.style = style;

							if (!handles.hInst)
								if (SDI::WinAPI::startIdeProcess)
								this->winProp.hInstance = SDI::WinAPI::startIdeProcess;
								else this->winProp.hInstance = NULL;
							else this->winProp.hInstance = handles.hInst;
							this->winProp.lpszClassName = className;
							this->winProp.lpszMenuName = menuName;
	
							if(!RegisterClassEx(&this->winProp)){
								SDI::basicMsg{ SDI::defaultMsgWorker,
								L"Incorect window init name", L"Window error", 1 }.doWork(); } }

						SDI_GL_DLL_API basicWindow(const WNDCLASSEX prop);

						SDI_GL_DLL_API ~basicWindow();

						SDI_GL_DLL_API WNDCLASSEX* getStruct();
						SDI_GL_DLL_API HWND getHandle() const override;
						SDI_GL_DLL_API HWND* getPointer() override;

						inline HWND makeWindow( LPCTSTR head,
												DWORD style,
												int x,
												int y,
												int xSize,
												int ySize,
												HWND hParent,
												HMENU hMenu
												/*LPVOID lParam*/)
						{	this->handleBase = CreateWindow(this->winProp.lpszClassName, head,
							style, x, y, xSize, ySize, hParent, hMenu, this->winProp.hInstance, NULL);

							if (!this->handleBase)
							SDI::basicMsg{ SDI::defaultMsgWorker, L"Window not create", L"Window error", 2 }.doWork();

							return this->handleBase; }

						SDI_GL_DLL_API void displayWindow(int style);
						SDI_GL_DLL_API void updateWindow(); };
	}
}

#define SDI_libWinAPICoreS0_incleder
#endif
