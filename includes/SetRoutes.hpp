#pragma once
#include "ITransport.hpp"
#include <string>
#include <vector>

class SetRoutes
{
private:
    std::vector<ITransport*> set_;
public:
    SetRoutes() {}

    ~SetRoutes() 
    {
        for (auto transport : set_)
        {
            delete transport;
        }
    }

    void Add(ITransport* transport) 
    {
        set_.push_back(transport);
    }

    int GetPrice()
    {
        int totalPrice = 0;
        for (ITransport* transport : set_)
        {
            totalPrice += transport->GetPrice();
        }
        return totalPrice;
    }

    std::vector<ITransport*> GetSet() 
    {
        return set_;
    }
};