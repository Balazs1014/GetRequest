#pragma once
#include <string>
#include <windows.h>
#include <wininet.h>
#pragma comment(lib, "wininet.lib")


class HttpRequest
{
private:
    void Initialize();
    void OpenConnection();
    std::string ReadResponse();

    std::wstring url_;
    HINTERNET hInternet_;
    HINTERNET hConnect_;
public:
    HttpRequest(const std::wstring& url);
    ~HttpRequest();

    std::string SendGetRequest();
};

