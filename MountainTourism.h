//
// Created by BeSmartTry on 17.12.2021.
//

#ifndef PROIECT2_MOUNTAINTOURISM_H
#define PROIECT2_MOUNTAINTOURISM_H


#include "HolidayResort.h"

class MountainTourism : public HolidayResort {
private:
    float height{};
    float distance{};
    int mountainTrails{};
public:
    MountainTourism() = default;
    ~MountainTourism() override = default;
    MountainTourism(const std::string &_tara, const std::string &_oras, const std::string &_denumire, float _pret, std::vector<Reviews *> _reviews, float _height, float _distance, int _mountainTrails);

    MountainTourism(const MountainTourism&) = default;

    MountainTourism &operator=(const MountainTourism&) ;

    void read(std::istream& is);
    void print(std::ostream& os) const;

};


#endif //PROIECT2_MOUNTAINTOURISM_H
