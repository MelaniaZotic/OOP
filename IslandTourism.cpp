//
// Created by BeSmartTry on 17.12.2021.
//

#include "IslandTourism.h"

IslandTourism::IslandTourism(const std::string &_tara, const std::string &_oras, const std::string &_denumire, float _pret, std::vector<Reviews *> _reviews,
                             int _noIsland, TypeOfView _view) : HolidayResort(tara, oras, denumire, pret,reviews )
{
    this->noIsland = _noIsland;
    this->view = _view;
}
IslandTourism &IslandTourism::operator=(const IslandTourism &i) {
    this->noIsland = i.noIsland;
    this->view = i.view;
}
std::istream &operator>>(std::istream &is, IslandTourism &islandTourism) {
   islandTourism.read(is);
    return is;
}

std::ostream &operator<<(std::ostream &os, const IslandTourism &islandTourism) {
    islandTourism.print(os);
    return os;
}

void IslandTourism::read(std::istream &is) {
    HolidayResort::read(is);
    std::cout<<"View: 0- SEAVIEW, 1- VIEW_OF_OCEAN: ";
    is >> reinterpret_cast<bool &>(view);
    std::cout <<"Number of islands: ";
    is >> noIsland;
}

void IslandTourism::print(std::ostream &os) const {
    HolidayResort::print(os);
    os<<"View: 0- SEAVIEW, 1- VIEW_OF_OCEAN:  "<<(view)<<'\n';
    os<<"Number of islands: "<<noIsland<<'\n';
}


















