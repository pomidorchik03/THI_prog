#pragma once
#include <string>

class ITransport
{
public:
    virtual ~ITransport() = default;
    virtual void ShowInfo() = 0;
    virtual int GetPrice() = 0;
    virtual std::string GetRoute() = 0;
    virtual std::string GetInfo() = 0;
    virtual void SetRoute(std::string route) = 0;
    virtual void SetPrice(int price) = 0;
};
