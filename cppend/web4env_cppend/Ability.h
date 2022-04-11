#pragma once
#include <string>
#include <map>
#include <json/json.h>
class Ability
{
public:
	static void Init();
	static std::map<std::string, void(*)(Json::Value params)> abilityMap;
	static void setHosts(Json::Value hosts);
};

