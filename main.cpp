#include <iostream>
#include <vector>
#include "HolidayResort.h"
#include "IslandTourism.h"
#include "MountainTourism.h"
#include <memory>

class TravelAgency {
private:
    std::vector<HolidayResort *> resorts;
    int MountainsDiscount{};
    int IslandDiscount{};
    int PercentileDiscount{};
public:
    TravelAgency(int mountainsDiscount, int islandDiscount, int percentileDiscount) : MountainsDiscount(
            mountainsDiscount), IslandDiscount(islandDiscount), PercentileDiscount(percentileDiscount) {}

    TravelAgency(const std::vector<HolidayResort *> &res) {
        for (auto *resort: res) {
            resorts.push_back(allocate(resort));
        }
    }

    // citirea a n resorturi
    void c1() {
        int nr;
        std::cout << " nr = ";
        std::cin >> nr;
        for (int i = 0; i < nr; i++) {
            std::cout << "Citeste resort " << i + 1 << '\n';
            resorts.push_back(createHoliday());
        }
    }

    //adaugare resort
    void adaugareR() {
        resorts.push_back(createHoliday());
    }

    void afisareR() {
        int i = 0;
        for (auto &res: resorts) {
            i++;
            std::cout << "Se afiseaza resortul: " << i << '\n';
            res->print(std::cout);
        }
    }

    // menu
    void showMenu() {
        std::cout << "---------------------------------" << '\n';
        std::cout << "1. Citeste n resorturi " << '\n';
        std::cout << "2. Adauga resort nou " << '\n';
        std::cout << "3. Afisaza resorturi " << '\n';
        std::cout << "4. Adauga discount" << '\n';
        std::cout << "5. Sumar" << '\n';
        std::cout << "6. Exit " << '\n';
    }

    void run() {
        int optiune;
        while (true) {
            showMenu();
            std::cout << "Optiune: ";
            std::cin >> optiune;

            if (optiune == 1) {
                c1();
            } else if (optiune == 2) {
                adaugareR();
            } else if (optiune == 3) {
                afisareR();
            } else if (optiune == 4) {
                adaugaDiscount();
            } else if (optiune == 5) {
                afiseazaSumar();
            } else { break; }
        }
    }

    HolidayResort *allocate(HolidayResort *h) {
        auto *asIsland = dynamic_cast<IslandTourism *>(h);
        auto *asMountain = dynamic_cast<MountainTourism *>(h);
        if (asIsland) {
            return new IslandTourism(*asIsland);
        } else if (asMountain) {
            return new MountainTourism(*asMountain);
        }
        return nullptr;

    }

    HolidayResort *createHoliday() {
        int tip;
        std::cout << "Tip vacanta (1 - Island, 2 - Mountain): ";
        std::cin >> tip;
        HolidayResort *h = nullptr;
        if (tip == 1) {
            h = new IslandTourism;
        } else if (tip == 2) {
            h = new MountainTourism;
        }
        if (h) {
            std::cin >> *h;
        }
        return h;

    }

    void adaugaDiscount() {

        std::cout << "IslandDiscount: ";
        std::cin >> IslandDiscount;
        std::cout << "MountainDiscount: ";
        std::cin >> MountainsDiscount;
        std::cout << "PercentileDiscount: ";
        std::cin >> PercentileDiscount;

    }

    void afiseazaSumar() {

        for (auto &res: resorts) {

            // calculez discountul cel mai mare care trebuie aplicat
            auto *islT = dynamic_cast<IslandTourism *>(res);
            if (islT) {

                if (islT->getPret() - IslandDiscount < islT->getPret() - PercentileDiscount / 100)
                    islT->setPret(islT->getPret() - IslandDiscount);
                else
                    islT->setPret(islT->getPret() - PercentileDiscount / 100);
            }

            auto *mounT = dynamic_cast<MountainTourism *>(res);
            if (mounT) {

                if (mounT->getPret() - MountainsDiscount < mounT->getPret() - PercentileDiscount / 100)
                    mounT->setPret(mounT->getPret() - MountainsDiscount);
                else
                    mounT->setPret(mounT->getPret() - PercentileDiscount / 100);
            }
        }
    }
};
int main()
{
    std::vector<HolidayResort*> v;
    TravelAgency app(v);
    app.run();
    return 0;
}
