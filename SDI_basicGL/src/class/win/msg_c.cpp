#include "SDI/Graphics/Window/Messange.h"
/*
SDI::byte SDI::defaultMsgWorker(const std::wstring text,
								const std::wstring head,
								const int code)*/

/*SDI::basicMsg::basicMsg(const doFunction fx, const std::wstring msg,
	const std::wstring head, const int code);*/

SDI::basicMsg::basicMsg(basicMsg* obj) : code(obj->code), msgHead(obj->msgHead),
msgText(obj->msgText), workFunction(obj->workFunction)
{ obj->~basicMsg(); }

int SDI::basicMsg::getCode() const
{ return this->code; }

std::wstring SDI::basicMsg::getHeadString() const
{ return this->msgHead; }

std::wstring SDI::basicMsg::getMsgStrng() const
{ return this->msgText; }

SDI::basicMsg::doFunction SDI::basicMsg::getFx() const
{ return this->workFunction; }

BYTE SDI::basicMsg::doWork() const
{	return this->workFunction(this->msgText, this->msgHead,
	this->code); }
BYTE SDI::basicMsg::tryWork(bool& tryOk) const
{	tryOk = true;
	try { return this->doWork(); }
	catch (...) { tryOk = false; return -1; } }
bool SDI::basicMsg::tryWork(BYTE& r) const
{	try { r = this->doWork(); return true; }
	catch (...) { return false; } }

bool SDI::basicMsg::operator > (classType& obj) const
{ return this->code > obj.code; }
bool SDI::basicMsg::operator < (classType& obj) const
{ return this->code < obj.code; }
bool SDI::basicMsg::operator >= (classType& obj) const
{ return this->code >= obj.code; }
bool SDI::basicMsg::operator <= (classType& obj) const
{ return this->code <= obj.code; }
bool SDI::basicMsg::operator == (classType& obj) const
{ return this->code > obj.code; }

std::wstring SDI::basicMsg::operator * () const
{ return this->msgHead; }
std::wstring SDI::basicMsg::operator & () const
{ return this->msgText; }
int SDI::basicMsg::operator ! () const
{ return this->code; }
BYTE SDI::basicMsg::operator ~ () const
{ return this->doWork(); }
