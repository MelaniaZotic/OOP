//
// Created by BeSmartTry on 17.12.2021.
//

#ifndef PROIECT2_ISLANDTOURISM_H
#define PROIECT2_ISLANDTOURISM_H

#include "HolidayResort.h"

enum TypeOfView{
    SEAVIEW,
    SEE_THE_OCEAN
};

class IslandTourism: public HolidayResort {
private:
    int noIsland{};
protected:
    bool view;
public:
    IslandTourism() = default;
    ~IslandTourism() override = default;
    IslandTourism(const std::string &tara, const std::string &oras, const std::string &denumire, float pret, std::vector<Reviews *> _reviews,
                  int noIsland, TypeOfView view);

    IslandTourism(const IslandTourism&) = default;
    IslandTourism &operator=(const IslandTourism&);

    friend std::istream& operator>>(std::istream& is, IslandTourism& islandTourism);
    friend std::ostream& operator<<(std::ostream& os, const IslandTourism& islandTourism);

    void read(std::istream& is) override;
     void print(std::ostream& os) const;

};


#endif //PROIECT2_ISLANDTOURISM_H
