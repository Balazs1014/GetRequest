#pragma once
#include <string>

class UI
{
public:
	UI();
	static std::wstring input(const std::string& sentence);
	static void displayLogo();
};

