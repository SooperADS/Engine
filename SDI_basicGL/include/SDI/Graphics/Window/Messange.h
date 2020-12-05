#pragma once

#ifndef SDI_libWinAPIFooBaseMsg_incleder
#define SDI_libWinAPIFooBaseMsg_incleder	

#include <string>
#include <locale>
#include <Windows.h>

#include "SDI/Graphics/GLCore.h"
#include "SDI/Basic/Types.h"

namespace SDI
{
	inline SDI::byte defaultMsgWorker(	const std::wstring text,
										const std::wstring head,
										const int code)
	{	UINT ut = 0;

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
		return 0; }

	constexpr byte(*defaultMsgWPtr)
	(const std::wstring, const std::wstring, const int) = defaultMsgWorker;

	class basicMsg
	{ public:		typedef ::SDI::byte(*doFunction)(	const std::wstring text,
														const std::wstring head,
														const int code );

					typedef basicMsg classType;
					
	protected:		const std::wstring msgText;
					const std::wstring msgHead;
					const int code;

					const doFunction workFunction;
					
	public:			basicMsg(const doFunction fx, const std::wstring msg,
					const std::wstring head, const int code) : code(code), msgHead(head),
					msgText(msg), workFunction(fx) {}
					basicMsg(const basicMsg&) = delete;
					SDI_GL_DLL_API basicMsg(basicMsg* obj);

					~basicMsg() = default;

					SDI_GL_DLL_API int getCode() const;
					SDI_GL_DLL_API std::wstring getHeadString() const;
					SDI_GL_DLL_API std::wstring getMsgStrng() const;
					SDI_GL_DLL_API doFunction getFx() const;

					SDI_GL_DLL_API BYTE doWork() const;
					SDI_GL_DLL_API BYTE tryWork(bool& tryOk) const;
					SDI_GL_DLL_API bool tryWork(BYTE& r) const;
					template<class catchFunction, class catchType>
					BYTE catchWork(catchFunction function)
					{	try { return this->doWork(); }
						catch (const catchType& obj)
						{ function(obj, this); } }

					SDI_GL_DLL_API bool operator > (classType& obj) const;
					SDI_GL_DLL_API bool operator < (classType& obj) const;
					SDI_GL_DLL_API bool operator >= (classType& obj) const;
					SDI_GL_DLL_API bool operator <= (classType& obj) const;
					SDI_GL_DLL_API bool operator == (classType& obj) const;

					SDI_GL_DLL_API std::wstring operator * () const;
					SDI_GL_DLL_API std::wstring operator & () const;
					SDI_GL_DLL_API int operator ! () const;
					SDI_GL_DLL_API BYTE operator ~ () const; };

	template<class data>
	class basicMsgWData : public basicMsg
	{ public:		using doFunction = SDI::byte(*)(	const std::wstring,
														const std::wstring,
														const int,
														const data*);
					using classType = basicMsgWData<data>;
					template<typename catchType> 
					using catchFunction = SDI::byte(*)(	const catchType&,
														const basicMsgWData<data>&);

	protected:		const doFunction workFunction;
					data dataValue;

	public:			basicMsgWData(const doFunction fx, const std::wstring msg,
					const std::wstring head, const int code, const data* other) 
					: workFunction( fx ), basicMsg(nullptr, msg, head, code)
					{ this->dataValue = *other; }
					basicMsgWData(const basicMsgWData&) = delete;
					basicMsgWData(basicMsgWData* obj) : code( obj->code ),
					msgHead( obj->msgHead ), msgText( obj->msgText ),
					workFunction( obj->workFunction )
					{	this->dataValue = obj->dataValue;
						obj->~basicMsg(); }

					~basicMsgWData() = default;

					virtual data* getData() 
					{ return &this->dataValue; }
					virtual BYTE doWork() const override
					{	return this->workFunction(this->msgText, this->msgHead,
						this->code, &this->dataValue); }

					operator data() const
					{ return this->dataValue; }	}; }

#endif
