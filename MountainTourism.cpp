//
// Created by BeSmartTry on 17.12.2021.
//

#include "MountainTourism.h"

MountainTourism::MountainTourism(const std::string &_tara, const std::string &_oras, const std::string &_denumire,
                                 float _pret,std::vector<Reviews *> _reviews, float _height, float _distance, int _mountainTrails): HolidayResort(tara,
                                                                                                                  oras,
                                                                                                                  denumire,
                                                                                                                  pret,
                                                                                                                  reviews)
{
    this->height = _height;
    this->distance  = _distance;
    this->mountainTrails = _mountainTrails;
}
MountainTourism &MountainTourism::operator=(const MountainTourism &m) {
    this->height = m.height;
    this->distance  = m.distance;
    this->mountainTrails = m.mountainTrails;
}

void MountainTourism::read(std::istream &is) {
    HolidayResort::read(is);
    std::cout<<" Height: ";
    is>>height;
    std::cout<<"Distance: ";
    is>>distance;
    std::cout<<"mountainTrails: ";
    is>>mountainTrails;
}

void MountainTourism::print(std::ostream &os) const {
    HolidayResort::print(os);
    os<<"Height: "<<height<<'\n';
    os<<"Distance: "<<distance<<'\n';
    os<<"mountainTrails: "<<mountainTrails<<'\n';
}

