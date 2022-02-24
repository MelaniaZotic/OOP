//
// Created by BeSmartTry on 17.12.2021.
//

#include "HolidayResort.h"

#include <utility>
HolidayResort::HolidayResort(const std::string &_tara, const std::string &_oras, const std::string &_denumire, float _pret ,
                             std::vector<Reviews *> _reviews){
    this->tara = _tara;
    this->oras = _oras;
    this->denumire = _denumire;
    this->pret = _pret;
    this->reviews = _reviews;

}
HolidayResort &HolidayResort::operator=(const HolidayResort &h) {
    this->tara = h.tara;
    this->tara = h.tara;
    this->oras = h.oras;
    this->denumire = h.denumire;
    this->pret = h.pret;
    this->reviews = h.reviews;
    return *this;
}

std::istream &operator>>(std::istream &is, HolidayResort &holidayResort) {
    holidayResort.read(is);
    return is;
}

std::ostream &operator<<(std::ostream &os, const HolidayResort &holidayResort) {
    holidayResort.print(os);
    return os;
}

void HolidayResort::read(std::istream &is) {
    std::cout<< "Tara: ";
    is >> tara;

    std::cout<<" Oras: ";
    is>>oras;

    std::cout<<"Denumire: ";
    is>>denumire;

    std:: cout << "Pret: ";
    is>>pret;

   std::cout<<"No.Reviews: ";
   int cntr;
   is>>cntr;
   reviews.reserve(cntr);
    for(int i = 0; i<cntr;i++) {
        auto *n = new Reviews();
        is >> (*n);
        reviews.push_back((*&n));
    }
}

void HolidayResort::print(std::ostream &os) const {
    os<<"Tara: "<<tara<<'\n';
    os<<"Oras: " <<oras<<'\n';
    os<<"Denumire: "<<denumire<<'\n';
    os<<"Price: "<<pret<<'\n';
    os<<"Reviews:";
    for(auto review : reviews)
    {
        os<<*review<<'\n';
    }
   // }
}

const std::string &HolidayResort::getTara() const {
    return tara;
}

const std::string &HolidayResort::getOras() const {
    return oras;
}

const std::string &HolidayResort::getDenumire() const {
    return denumire;
}

double HolidayResort::getPret() const {
    return pret;
}

const std::vector<Reviews *> &HolidayResort::getReviews() const {
    return reviews;
}

void HolidayResort::setTara(const std::string &tara) {
    HolidayResort::tara = tara;
}

void HolidayResort::setOras(const std::string &oras) {
    HolidayResort::oras = oras;
}

void HolidayResort::setDenumire(const std::string &denumire) {
    HolidayResort::denumire = denumire;
}

void HolidayResort::setPret(double pret) {
    HolidayResort::pret = pret;
}

void HolidayResort::setReviews(const std::vector<Reviews *> &reviews) {
    HolidayResort::reviews = reviews;
}

