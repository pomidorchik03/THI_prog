#pragma once
#include "LandTransport.hpp"

class Train : public LandTransport
{
protected:
    int countCarriage_;
public:
    Train(const std::string route, const int price, const std::vector<std::string> stops, const int countCarriage) : LandTransport(route, price, stops), countCarriage_(countCarriage) {}
    void ShowInfo() override;
};