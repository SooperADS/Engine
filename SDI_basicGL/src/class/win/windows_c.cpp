#include "framework.h"
#include "SDI/Graphics/Window/Core.h"
#include "SDI/Graphics/Window/Messange.h"

template<typename handleType>
inline handleType SDI::WinAPI::basicWinAPIObject<handleType>::getHandle() const
{ return this->handleBase; }

template<typename handleType>
inline handleType* SDI::WinAPI::basicWinAPIObject<handleType>::getPointer()
{ return &this->handleBase; }

SDI::WinAPI::basicWindow::basicWindow()
{	this->winProp.cbSize = sizeof(this->winProp);
	this->winProp.cbWndExtra = 0;
	this->winProp.cbClsExtra = 0;
	this->winProp.lpfnWndProc = this->defaultMassangeWorkr;
	this->winProp.hbrBackground = NULL;
	this->winProp.hCursor = NULL;
	this->winProp.hIcon = NULL;
	this->winProp.hIconSm = NULL;
	this->winProp.hInstance = SDI::WinAPI::startIdeProcess;
	this->winProp.lpszClassName = NULL;
	this->winProp.lpszMenuName = NULL;
	this->winProp.style = CS_HREDRAW | CS_VREDRAW; }

SDI::WinAPI::basicWindow::basicWindow(const basicWindow& obj)
{ this->winProp = obj.winProp; }

SDI::WinAPI::basicWindow::basicWindow(basicWindow* obj)
{	this->winProp = obj->winProp;
	obj->~basicWindow(); }

/*
SDI::WinAPI::basicWindow::basicWindow(  const UINT style,
										const WNDPROC function,
										const SDI::WinAPI::basicWindow::windHandles handles,
										const LPCTSTR className,
										const LPCTSTR menuName)*/

/*
HWND SDI::WinAPI::basicWindow::makeWindow(	LPCTSTR head,
											DWORD style,
											int x,
											int y,
											int xSize,
											int ySize,
											HWND hParent,
											HMENU hMenu
											/*LPVOID lParam*//*);*/

SDI::WinAPI::basicWindow::basicWindow(const WNDCLASSEX prop)
{ this->winProp = prop; }

SDI::WinAPI::basicWindow::~basicWindow() {}

WNDCLASSEX* SDI::WinAPI::basicWindow::getStruct()
{ return &this->winProp; }

HWND SDI::WinAPI::basicWindow::getHandle() const
{ return this->handleBase; }

HWND* SDI::WinAPI::basicWindow::getPointer()
{ return &this->handleBase; }

void SDI::WinAPI::basicWindow::displayWindow(int style)
{ ShowWindow(this->handleBase, style); }

void SDI::WinAPI::basicWindow::updateWindow()
{ UpdateWindow(this->handleBase); }

void SDI::WinAPI::registrHandle(HINSTANCE h)
{ SDI::WinAPI::startIdeProcess = h; }

//HINSTANCE SDI::WinAPI::startIdeProcess = 0;
