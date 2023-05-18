#include <iostream>
#include "UI.hpp"
#include "HttpRequest.hpp"


int main()
{
	UI::displayLogo();
	const std::wstring input = UI::input("Type in the url:");
    try {
        HttpRequest request(input);
        const std::string response = request.SendGetRequest();
        std::cout << "Response:\n" << response << std::endl;
    }
    catch (...) {
        std::cerr << "exception occurred." << std::endl;
        return 1;
    }

    return 0;
}