#ifndef UFC_SIMULATOR_USERINTERFACE_H
#define UFC_SIMULATOR_USERINTERFACE_H

#include "Tournament.h"

class UserInterface {
public:
    void displayMenu();
    void startTournament();
    void chooseWeightSimulation(Tournament& UFCTournament);
    void chooseweighClass();
};

#endif //UFC_SIMULATOR_USERINTERFACE_H
