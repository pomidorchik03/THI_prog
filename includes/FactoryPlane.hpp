#pragma once
#include "FactoryTransport.hpp"
#include "../lib/Plane.hpp"

class FactoryPlane : public FactoryTransport
{
private:
    int count_;
public:
    ITransport* create(std::string route, int price, int maxAltitude, std::string nameAirline)
    {
        count_++;
        return new Plane(route, price, maxAltitude, nameAirline);
    }
    void info() override
    {
        std::cout << "This class for creating plane" << "\n";
        std::cout << "Created planes: " << count_ << "\n\n";
    }
};
