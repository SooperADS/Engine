#include "SDI/Basic/Builder.h"
#include <fstream>

#pragma warning ( disable : 4273 )

std::string SDI::getWordFStr(const std::string& from, SDI::uint& it)
{
	std::string word;

	char charSip = '\0';
	if (from[it] == '\'' || from[it] == '\"')
	{ charSip = from[it]; it++; }
	
	word = getWord(from, it);

	if (word[it - 1] == charSip)
	{ word.pop_back(); it--;}

	return word; }
std::string SDI::getWord(const std::string& from, SDI::uint& it)
{	std::string word;

	SDI::skipSpaces(from, it);

	while (!isSpace(from[it]))
	{	word.push_back(from[it]);
		it++; }

	return word; }

std::string SDI::getNextWord(const std::string& from, SDI::uint& it)
{	SDI::skipSpaces(from, it);
	return SDI::getWord(from, it); }
std::string SDI::getNextWordFStr(const std::string& from, SDI::uint& it)
{	SDI::skipSpaces(from, it);
	return SDI::getWordFStr(from, it);}

float SDI::getFLOATValue(const std::string& from, SDI::uint& it)
{	float r = std::stof(getWordFStr(from, it));
	return r; }

int SDI::getINTValue(const std::string& from, SDI::uint& it)
{	int r = std::stoi(getWordFStr(from, it));
	return r; }

void SDI::skipSpaces(const std::string& from, SDI::uint& it)
{	while (isSpace(from[it]))
	it++; }

bool SDI::isSpace(const char& obj)
{ return (/*SDI::ScaneLoadLang::Spaces->isFind(obj)*/1); }
