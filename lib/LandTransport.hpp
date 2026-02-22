#pragma once
#include "../includes/AbstractTransport.hpp"
#include <vector>

class LandTransport : public AbstractTransport
{
protected: 
    std::vector<std::string> stops_;
public:
    LandTransport(const std::string route, const int price, const std::vector<std::string> stops) : AbstractTransport(route, price), stops_(stops) {}
};
