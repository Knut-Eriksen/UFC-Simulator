#ifndef UFC_SIMULATOR_FIGHTERS_H
#define UFC_SIMULATOR_FIGHTERS_H

#include <iostream>
#include <string>
#include <vector>

class Fighter {
public:
    std::string name;
    std::string nationality;
    int rank;
    int striking;
    int grappling;
    int stamina;

    Fighter(const std::string& name, const std::string& nationality,
            int rank, int striking, int grappling, int stamina)
            : name(name), nationality(nationality),
              rank(rank), striking(striking), grappling(grappling), stamina(stamina) {}

    static void displayWeightClassStats(const std::vector<Fighter> &fighters){
        std::cout << "\n******************************************************\n\n";
        for (int i = 0; i < fighters.size(); ++i) {
            std::cout << fighters[i].rank << ". " << fighters[i].name << " - Striking: " << fighters[i].striking << " - Grappling: " << fighters[i].grappling << " - Stamina: " << fighters[i].stamina << "\n";
        }
        std::cout << "\n******************************************************\n\n";
    }
};

extern std::vector<Fighter> HW;
extern std::vector<Fighter> LHW;
extern std::vector<Fighter> MW;
extern std::vector<Fighter> WW;
extern std::vector<Fighter> LW;
extern std::vector<Fighter> FW;
extern std::vector<Fighter> BW;
extern std::vector<Fighter> FLW;

void populateFighters();

#endif //UFC_SIMULATOR_FIGHTERS_H
