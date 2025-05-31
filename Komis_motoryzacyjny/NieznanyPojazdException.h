#pragma once
#include <exception>
#include <string>

using namespace std;

class NieznanyPojazdException : public exception
{
    string komunikat;

public:
    NieznanyPojazdException(const string& msg) : komunikat(msg) {}

    const char* what() const noexcept override
    {
        return komunikat.c_str();
    }
};