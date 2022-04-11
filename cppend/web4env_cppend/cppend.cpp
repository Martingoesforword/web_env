// cppend.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "all.h"
#include <iostream>
#include "Util.h"
#include "Ability.h"

const auto p = u8"[placeholderstart-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-"
u8"[placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-"
u8"[placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-"
u8"[placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-"
u8"[placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholderend"
u8"]";
int main()
{
	std::string str = Util::Utf8ToString(p);
	Json::Value jsonData;
	Json::Reader reader;
	if (reader.parse(str.c_str(), jsonData) && jsonData.size())
	{
		Json::Value ability = jsonData["ability"];
		auto abilityName = ability.asString();
		Ability::Init();

		Json::Value params = jsonData["params"];
		if (Ability::abilityMap.find(abilityName) != Ability::abilityMap.end()) {
			auto func = Ability::abilityMap[abilityName];
			func(params);
		}
	}
	system("pause");
}
