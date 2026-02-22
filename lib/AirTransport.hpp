#pragma once
#include "../includes/AbstractTransport.hpp"

class AirTransport : public AbstractTransport
{
protected:
    int maxAltitude_;
public:
    AirTransport(const std::string route, const int price, const int maxAltitude) : AbstractTransport(route, price), maxAltitude_(maxAltitude) {}
};
