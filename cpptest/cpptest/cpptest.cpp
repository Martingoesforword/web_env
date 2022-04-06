// cpptest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "windows.h"

const auto p = u8"[placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-"
u8"[placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-"
u8"[placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-"
u8"[placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-"
u8"[placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-placeholder-"
u8"]";
std::string Utf8ToString(std::string strUtf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)strUtf8.c_str(), -1, NULL, 0);
	unsigned short* wszGBK = new unsigned short[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)strUtf8.c_str(), -1, (LPWSTR)wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, szGBK, len, NULL, NULL);
	std::string ret(szGBK);
	if (NULL != szGBK)
	{
		delete[] szGBK;
		szGBK = NULL;
	}
	if (NULL != wszGBK)
	{
		delete[] wszGBK;
		wszGBK = NULL;
	}
	return ret;
}
int main()
{
    std::cout << Utf8ToString(p);
	system("pause");
}
