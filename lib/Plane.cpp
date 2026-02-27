#include "Plane.hpp"

void Plane::ShowInfo()
{
    std::cout << "Route: " << this->route_ << '\n';
    std::cout << "Cost route: " << this->price_ << "\n";
    std::cout << "Stop: " << this->maxAltitude_ << '\n';
    std::cout << "Standing places: " << this->nameAirline_ << "\n\n";
}

std::string Plane::GetInfo()
{
    return  "PLANE           Route: " + route_ + "   | Price: " + std::to_string(price_) + "   | Max Altitude: " + std::to_string(maxAltitude_) + "   | Name Airline: " + nameAirline_;
}

int Plane::GetMaxAltitude()
{
    return maxAltitude_;
}

std::string Plane::GetNameAirline()
{
    return nameAirline_;
}

void Plane::SetMaxAltitude(int maxAltitude)
{
    maxAltitude_ = maxAltitude;
}

void Plane::SetNameAirline(std::string nameAirline)
{
    nameAirline_ = nameAirline;
}

