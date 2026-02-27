#pragma once
#include <string>
#include <iostream>
#include "ITransport.hpp"

class AbstractTransport : public ITransport
{
protected:
    std::string route_;
    int price_;
public:
    AbstractTransport(const std::string route, const int price) : route_(route), price_(price) {};
    int GetPrice() override { return this->price_; }
    std::string GetRoute() override { return this->route_; }
    void SetRoute(std::string route) override { route_ = route; };
    void SetPrice(int price) override {price_ = price; };
};