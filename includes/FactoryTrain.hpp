#pragma once
#include "FactoryTransport.hpp"
#include "../lib/Train.hpp"

class FactoryTrain : public FactoryTransport
{
private: 
    int count_;
public:
    ITransport* create(std::string route, int price, std::vector<std::string> stops, int countCarriage)
    {
        count_++;
        return new Train(route, price, stops, countCarriage);
    }
    void info() override
    {
        std::cout << "This class for creating train" << "\n";
        std::cout << "Created planes: " << count_ << "\n\n";
    }
};
