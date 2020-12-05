#pragma once
#include <string>
#include <vector>

#include "Types.h"
#include "Objects.h"

#ifndef ___sdiFONDATION_h__basicSDIBuilder
#define ___sdiFONDATION_h__basicSDIBuilder

#ifndef __sdi_foundationObjectLib_API
#if (SDI_IMPORT_API & 0b00001)
#define __sdi_foundationObjectLib_API __declspec(dllexport)
#else
#define __sdi_foundationObjectLib_API __declspec(dllimport)
#endif
#endif // !__sdi_foundationObjectLib_API

namespace SDI
{	
	/*struct ScaneLoadLang
	{ private:	static SDI::Basic_SDIDictionary<std::string> scaneOperators;
				static SDI::Basic_SDIDictionary<std::string> scaneKeyords;
				/*static SDI::Basic_SDIDictionary<char> scaneSpaces;*/

	/*public:		~ScaneLoadLang() = delete;
				static void mainInit();	
	
				/*static const SDI::Basic_SDIDictionary<char>* Spaces;*/
				/*static const SDI::Basic_SDIDictionary<std::string>* Keywords;
				static const SDI::Basic_SDIDictionary<std::string>* Operators; };*/

	std::string SDI_DLL_API_H getWordFStr(const std::string&
	from, SDI::uint& it);
	std::string SDI_DLL_API_H getWord(const std::string&
	from, SDI::uint& it);
	std::string SDI_DLL_API_H getNextWord(const std::string&
	from, SDI::uint& it);
	std::string SDI_DLL_API_H getNextWordFStr(const std::string&
	from, SDI::uint& it);
	float SDI_DLL_API_H getFLOATValue(const std::string&
	from, SDI::uint& it);
	int SDI_DLL_API_H getINTValue(const std::string&
	from, SDI::uint& it);
	void SDI_DLL_API_H skipSpaces(const std::string&
	from, SDI::uint& it); 

	bool SDI_DLL_API_H isSpace(const char& obj);
	}

#endif