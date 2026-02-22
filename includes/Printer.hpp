#pragma once
#include "ITransport.hpp"
#include "SetRoutes.hpp"
#include <iostream>

class Printer
{
public:
    Printer() {}
    ~Printer() {}

    void Print(ITransport* transport)
    {
        std::cout << "Route: " << transport->GetRoute() << ", price: " << transport->GetPrice() << "\n\n";
    }

    void Print(SetRoutes& set)
    {
        std::cout << "In set: " << "\n";
        for (auto transport : set.GetSet())
        {
            std::cout << "Route: " << transport->GetRoute() << ", price: " << transport->GetPrice() << "\n";
        }
        std::cout << "\n";
    }
};