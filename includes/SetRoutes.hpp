#pragma once
#include "ITransport.hpp"
#include <string>
#include <vector>

class SetRoutes
{
private:
    std::vector<ITransport*> transports_;
public:
    SetRoutes() {}

    ~SetRoutes() 
    {
        for (auto transport : transports_)
        {
            delete transport;
        }
    }

    void Add(ITransport* transport) 
    {
        transports_.push_back(transport);
    }

    void Delete(int index)
    {
        delete transports_[index];
        transports_.erase(transports_.begin() + index);
    }

    int GetPrice()
    {
        int totalPrice = 0;
        for (ITransport* transport : transports_)
        {
            totalPrice += transport->GetPrice() * 2;
        }
        return totalPrice;
    }

    ITransport* GetTransport(int index)
    {
        return transports_[index];
    }

    std::vector<ITransport*> GetTransports() 
    {
        return transports_;
    }

    void SetTransports(std::vector<ITransport*> transports)
    {
        transports_ = transports;
    }
};