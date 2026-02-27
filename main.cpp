#include <iostream>
#include "includes/Printer.hpp"
#include "includes/FactoryTransport.hpp"
#include "includes/SetRoutes.hpp"
#include "includes/FactoryTrain.hpp"
#include "includes/FactoryPlane.hpp"

int main()
{
    SetRoutes sr;
    FactoryTrain ft;
    FactoryPlane fp;
    Printer pr;

    fp.create("a-b", 100, 20, "air")->ShowInfo();
    ft.create("a-b", 100, {"c","d"}, 3)->ShowInfo();

    fp.info();

    sr.Add(ft.create("a-b", 100, {"c","d"}, 3));
    sr.Add(fp.create("a-b", 100, 3, "air"));
    sr.Delete(0);

    pr.Print(ft.create("a-b", 100 , {"n","aasdwwdasdwasd wasd w"}, 4));
    pr.Print(sr);
    std::cout << sr.GetPrice();
}
