#include "UI.hpp"

#include <iostream>

UI::UI() = default;

std::wstring UI::input(const std::string& sentence)
{
	std::wstring input{};
	std::cout << sentence << std::endl;
	std::wcin >> input;
	return input;

}
void UI::displayLogo()
{
	std::cout << " _____  _____ _____ " << std::endl;
	std::cout << "|  __ \\|  ___|_   _|" << std::endl;
	std::cout << "| |  \\/| |__   | |  " << std::endl;
	std::cout << "| | __ |  __|  | |  " << std::endl;
	std::cout << "| |_\ \| |___  | |  " << std::endl;
	std::cout << " \____/\____/  \_/  " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}