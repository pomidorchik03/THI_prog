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

std::string Train::GetInfo()
{
    std::string collect_stops = "";
    for (auto s : stops_)
    {
        collect_stops += s + ", ";
    }
    if (collect_stops.length() > 2)
    {
        collect_stops.pop_back();
        collect_stops.pop_back();
    }
    return "TRAIN            Route: " + route_ + "   | Price: " + std::to_string(price_) + "   | Stops: " + collect_stops + "   | CountCarriage: " + std::to_string(countCarriage_);
}

std::vector<std::string> Train::GetStops()
{
    return stops_;
}

int Train::GetCountCarriage()
{
    return countCarriage_;
}

void Train::SetStops(std::vector<std::string> stops)
{
    stops_ = stops;
}

void Train::SetCountCarriage(int countCarriage)
{
    countCarriage_ = countCarriage;
}