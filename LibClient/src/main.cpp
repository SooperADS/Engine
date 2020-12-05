#include "framework.h"

#include "SDI/Graphics/Window/Messange.h"

#include <thread>
#include <chrono>
#include <deque>
#include <stack>

#pragma warning ( disable : 6387 )

//#define vmb 10000

LRESULT CALLBACK WinProc(	HWND window,
							UINT smsg,
							WPARAM params,
							LPARAM lmsg);

SDI::byte defaultMsgWorker(const std::wstring text,
							const std::wstring head,
							const int code)
{
	UINT ut = 0;

	if (code < 1000)
	{ ut = MB_ICONERROR; }
	else if (code < 5000)
	{ ut = MB_ICONWARNING; }
	else if (code < 10000)
	{ ut = MB_ICONINFORMATION; }
	else { return 1; }

	std::wstring wt = text;
	wt += L"\n\nCode: ";
	wt += std::to_wstring(code);

	MessageBox(0, wt.c_str(), head.c_str(), ut | MB_OK);
	return 0;
}

startPointAPI(handle, h64, cmd, cmds)
{
	if (!SDI::Libs::LibGL_Init())
	{
		SDI::basicMsg msg{ defaultMsgWorker , L"SDI lib: \"SDI_basicGraphicsLib\" not load", L"Error -1 :(", -1 };
		msg.doWork();
		return -1;
	}

	MessageBoxW(0, L"Hello yuopta)", L"Hi", MB_ICONINFORMATION );

	SDI::WinAPI::basicWindow::windHandles def01{};
	def01.hbrBack = (HBRUSH)GetStockObject(BLACK_BRUSH);
	def01.hCursor = LoadCursor(NULL, IDC_ARROW);
	def01.hInst = handle;
	def01.hIconMini = LoadIcon(NULL, IDI_WARNING);
	def01.hIcon = LoadIcon(NULL, IDI_WINLOGO);

	SDI::WinAPI::basicWindow win{ CS_HREDRAW | CS_VREDRAW, WinProc, def01, L"first", NULL };
	win.makeWindow(L"Hello wold", WS_OVERLAPPEDWINDOW | WS_VSCROLL, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, 0, 0);

	win.displayWindow(cmds);
	win.updateWindow();

	MSG msg;
	while(GetMessage(&msg, NULL, NULL, NULL)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WinProc (	HWND hWnd, 
							UINT uMsg,
							WPARAM wParam,
							LPARAM lParam)
{	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;
	COLORREF colorText = RGB(255, 0, 0); // задаём цвет текста

	switch (uMsg) {
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);
		SetTextColor(hDC, colorText);
		DrawText(hDC, L"Hello Youpta", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); // рисуем текст
		EndPaint(hWnd, &ps); // заканчиваем рисовать
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam); // если закрыли окошко
	}

	return NULL; // возвращаем значение
}
