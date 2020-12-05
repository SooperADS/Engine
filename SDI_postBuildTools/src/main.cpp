#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>

#include "SDI/Basic/Types.h"

#define sys system

// Comands:
//
// clear:
// |- clear out <outDirName> [configs] : [platforms] : [projectsNanes] : [filesEnd] 
// |- try range <min> <max> <cmd> ...
// |- try only <code> <cmd> ...
// |- try not <code> <cmd> ...
// |- try out <cmd> ...
//

int main(SDI::uint argCount, char* args[])
{
	std::cout << "Comand started\n";

	std::vector<std::string> comands{};

	for (size_t i = 0; i < argCount; i++)
	comands.push_back(args[i]);

	try 
	{ if (comands.at(1) == "clear")
		{	if (comands.at(2) == "out")
			{	if (argCount < 4)
				{ throw; }
				else
				{	std::string dir = args[0];

					for (int i = (dir.size() - 1); i >= 0; i--)
					{	if (dir[i] == '\\')
						{ break; }
						else { dir.pop_back(); } }

					dir += comands[3];
					dir += '\\';

					if (dir[0] == '\\')
					{ dir.erase(0); }

					SDI::uint i = 4;
					std::vector<std::string> cNames;
					while (!(comands.at(i) == ":"))
					{ cNames.push_back(comands[i] + '\\'); i++; }
					i++;

					std::vector<std::string> plNames;
					while (!(comands.at(i) == ":"))
					{ plNames.push_back('x' + comands[i] + '\\'); i++; }
					i++;

					std::vector<std::string> pNames;
					while (!(comands.at(i) == ":"))
					{ pNames.push_back(comands[i]); i++; }
					i++;

					std::vector<std::string> fends;
					for (size_t j = i; j < comands.size(); j++)
					{ fends.push_back("." + comands.at(j)); }

					pNames.shrink_to_fit();
					fends.shrink_to_fit();

					std::vector<std::string> dirsN;

					if (plNames.size() == 0)
					{ plNames.push_back("\0"); }

					if (cNames.size() == 0)
					{ cNames.push_back("\0"); }

					int j = 0;
					do {int k = 0;
						do {std::string p = (dir + plNames[k] + cNames[j]);
							dirsN.push_back(p); 
							k++; } while (k < plNames.size());
						j++; } while (j < cNames.size());

					std::vector<std::string> dpn;
					for (j = 0; j < dirsN.size(); j++)
					{	for (size_t k = 0; k < pNames.size(); k++)
						{ dpn.push_back(dirsN[j] + pNames[k]); } }

					cNames.~vector();
					plNames.~vector();
					dirsN.~vector();
					pNames.~vector();

					std::vector<std::string> ffn;

					for (size_t j = 0; j < dpn.size(); j++)
					{	for (size_t k = 0; k < fends.size(); k++)
						{ ffn.push_back(dpn[j] + fends[k]); } }

					pNames.~vector();
					fends.~vector();

					for (i = 0; i < ffn.size(); i++)
					{	if(remove(ffn[i].c_str()) == -1)
						printf(std::string{ "file: \"" + ffn[i] + "\" can't be delete!\n" }.c_str()); }
					return 0; } } }
	else if (comands.at(1) == "try")
	{	if (comands.at(2) == "range")
		{	int min, max, r;

			min = std::stoi(comands.at(3));
			max = std::stoi(comands.at(4));
			
			std::string rs = comands[5];
			for (size_t i = 6; i < argCount; i++) rs = (rs + ' ' + args[i]);

			r = system(rs.c_str());
	
			if (r > max || r < min) return r;
			else return 0; }
		else if(comands.at(2) == "only")
		{	int is, r;

			is = std::stoi(comands.at(3));

			std::string rs = comands[4];
			for (size_t i = 5; i < argCount; i++) rs = (rs + ' ' + args[i]);

			r = system(rs.c_str());

			if (r == is) return r;
			else return 0;  }
		else if(comands.at(2) == "not")
		{	int is, r;

			is = std::stoi(comands.at(3));

			std::string rs = comands[4];
			for (size_t i = 5; i < argCount; i++) rs = (rs + ' ' + args[i]);

			r = system(rs.c_str());

			if (r != is) return r;
			else return 0;  }
		else if (comands.at(2) == "out")
		{	std::string rs = comands[3];
			for (size_t i = 4; i < argCount; i++) rs = (rs + ' ' + args[i]);

			system(rs.c_str());
			return 0; } } }
	catch (...)
	{ std::cout << "incorect imput data\n"; }

	sys("pause");
	return -1;
}
