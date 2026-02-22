#include "Train.hpp"

void Train::ShowInfo()
{
    std::cout << "Route: " << this->route_ << '\n';
    std::cout << "Cost route: " << this->price_ << "\n";
    for(auto stop : this->stops_ )
        std::cout << "Stop: " << stop << ", ";
    std::cout << '\n';
    std::cout << "Standing places: " << this->countCarriage_ << "\n\n";
}