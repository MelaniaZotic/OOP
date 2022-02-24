//
// Created by BeSmartTry on 17.12.2021.
//

#ifndef PROIECT2_REVIEWS_H
#define PROIECT2_REVIEWS_H


#include <string>

class Reviews {
private:
    std::string name;
    int time{};
    int note{};
public:
    Reviews()=default;
    ~Reviews() = default;
    Reviews(const std::string &_name, int _time, int _note);
    Reviews(const Reviews&) = default;
    Reviews &operator=(const Reviews&);

    friend std::istream& operator>>(std::istream& is, Reviews& reviews);
    friend std::ostream& operator<<(std::ostream& os, const Reviews& reviews);

    virtual void read(std::istream& is);
    virtual void print(std::ostream& os) const;
};


#endif //PROIECT2_REVIEWS_H
