#include "Ability.h"
#include <fstream>
#include <iostream>
#include "windows.h"

using namespace std;

std::map<std::string, void(*)(Json::Value params)> Ability::abilityMap;
void Ability::Init()
{
	abilityMap["setHosts"] = setHosts;
}

void Ability::setHosts(Json::Value params)
{
	if (params.size()) {
		Json::Value hosts = params["hosts"];
		auto strHosts = hosts.asString();
		//使用strHost附加到host文件
        ofstream outf;
        const char* lpFileName = "C:\\Windows\\System32\\drivers\\etc\\hosts";
        DWORD   dwAttribute = ::GetFileAttributes(lpFileName);
        DWORD   wrAttribute = dwAttribute;
        if (dwAttribute & FILE_ATTRIBUTE_READONLY)
        {
            wrAttribute = dwAttribute & ~FILE_ATTRIBUTE_READONLY;
            SetFileAttributes(lpFileName, wrAttribute);//去掉只读属性
        }
        system("color 0A");

        outf.open("C:\\Windows\\System32\\drivers\\etc\\hosts");//覆盖
        outf << "\n";
        outf << strHosts;
        outf << "\n";
        outf.close();
        SetFileAttributes(lpFileName, dwAttribute);//恢复只读属性
        return;
	}
}
