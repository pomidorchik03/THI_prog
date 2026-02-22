#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class FactoryTransport
{
public:
    ~FactoryTransport() {};
    virtual void info()
    {
        std::cout << "This class is for creating routes" << "\n\n";
    }
};

