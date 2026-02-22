#pragma once
#include <string>

class ITransport
{
public:
    virtual ~ITransport() = default;
    virtual void ShowInfo() = 0;
    virtual int GetPrice() = 0;
    virtual std::string GetRoute() = 0;
};