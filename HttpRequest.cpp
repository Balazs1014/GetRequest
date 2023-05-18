#include "HttpRequest.hpp"

#include <iostream>

HttpRequest::HttpRequest(const std::wstring& url){
    url_ = url;
    hInternet_ = nullptr;
    hConnect_ = nullptr;
    Initialize();
}

HttpRequest::~HttpRequest() {
    if (hConnect_)
        InternetCloseHandle(hConnect_);
    if (hInternet_)
        InternetCloseHandle(hInternet_);
}

void HttpRequest::Initialize() {
    hInternet_ = InternetOpen(L"HTTPGET", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (hInternet_ == NULL) {
        std::cerr << "Failed to initialize WinINet." << std::endl;
        throw std::runtime_error("Failed to initialize WinINet.");
    }
}

void HttpRequest::OpenConnection() {
    hConnect_ = InternetOpenUrl(hInternet_, url_.c_str(), nullptr, 0, INTERNET_FLAG_RELOAD, 0);
    if (hConnect_ == nullptr) {
        std::cerr << "Failed to open the URL." << std::endl;
        throw std::runtime_error("Failed to open the URL.");
    }
}

std::string HttpRequest::ReadResponse() {
    const int BUFFER_SIZE = 4096;
    char buffer[BUFFER_SIZE];
    std::string response;
    DWORD bytesRead;

    while (InternetReadFile(hConnect_, buffer, BUFFER_SIZE - 1, &bytesRead) && bytesRead > 0) {
        buffer[bytesRead] = '\0';
        response += buffer;
    }

    return response;
}

std::string HttpRequest::SendGetRequest() {
    OpenConnection();
    std::string response = ReadResponse();

    return response;
}