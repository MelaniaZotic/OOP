//
// Created by BeSmartTry on 17.12.2021.
//

#include <iostream>
#include "Reviews.h"

Reviews::Reviews(const std::string &_name, int _time, int _note) {
    this->name = _name;
    this->time = _time;
    this->note = _note;
}
Reviews &Reviews::operator=(const Reviews &r) {
    this->name = r.name;
    this->time = r.time;
    this->note = r.note;
    return *this;
}

std::istream &operator>>(std::istream &is, Reviews &reviews) {
    reviews.read(is);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Reviews &reviews) {
    reviews.print(os);
    return os;
}

void Reviews::read(std::istream &is) {
    std::cout<<"Name: ";
    is >> name;
    std::cout<<"Time: ";
    is >> time;
    std::cout<<"Note: ";
    is >> note;
}

void Reviews::print(std::ostream &os) const {
    os<<"Name: "<<name<<'\n';
    os<<"Time: "<<time<<'\n';
    os<<"Note: "<<note<<'\n';

}

