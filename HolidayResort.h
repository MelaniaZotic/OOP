//
// Created by BeSmartTry on 17.12.2021.
//

#ifndef PROIECT2_HOLIDAYRESORT_H
#define PROIECT2_HOLIDAYRESORT_H
#include<iostream>
#include <vector>
#include "Reviews.h"
#include <memory>

class HolidayResort {
protected:
    std::string tara;
    std::string oras;
    std::string denumire;
    double pret{};
    std::vector<Reviews *> reviews;
public:
    HolidayResort() = default;
    virtual ~HolidayResort() = default;
    HolidayResort(const std::string &_tara, const std::string &_oras, const std:: string &_denumire, float _pret, std::vector<Reviews *> _reviews);
    HolidayResort(const HolidayResort&) = default;
    HolidayResort &operator=(const HolidayResort&);

    friend std::istream& operator>>(std::istream& is, HolidayResort& holidayResort);
    friend std::ostream& operator<<(std::ostream& os, const HolidayResort& holidayResort);

    virtual void read(std::istream& is);
    virtual void print(std::ostream& os) const;

    const std::string &getTara() const;

    const std::string &getOras() const;

    const std::string &getDenumire() const;

    double getPret() const;

    const std::vector<Reviews *> &getReviews() const;

    void setTara(const std::string &tara);

    void setOras(const std::string &oras);

    void setDenumire(const std::string &denumire);

    void setPret(double pret);

    void setReviews(const std::vector<Reviews *> &reviews);

};


#endif //PROIECT2_HOLIDAYRESORT_H
