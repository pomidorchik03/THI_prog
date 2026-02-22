#pragma once
#include "AirTransport.hpp"

class Plane : public AirTransport
{
protected: 
    std::string nameAirline_;
public: 
    Plane(const std::string route, const int price, const int maxAltitude, const std::string nameAirline) : AirTransport(route, price, maxAltitude), nameAirline_(nameAirline) {}
    void ShowInfo() override;
};