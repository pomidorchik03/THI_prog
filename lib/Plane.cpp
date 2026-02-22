#include "Plane.hpp"

void Plane::ShowInfo()
{
    std::cout << "Route: " << this->route_ << '\n';
    std::cout << "Cost route: " << this->price_ << "\n";
    std::cout << "Stop: " << this->maxAltitude_ << '\n';
    std::cout << "Standing places: " << this->nameAirline_ << "\n\n";
}