#ifndef UFC_SIMULATOR_TOURNAMENT_H
#define UFC_SIMULATOR_TOURNAMENT_H

#include "fighters.h"

class Tournament {
public:
    int tournamentId;
    std::string name;

    Tournament(int tournamentId, const std::string& name) : tournamentId(tournamentId), name(name) {}

    void simulateTournament(std::vector<Fighter>& fighters);
};

#endif //UFC_SIMULATOR_TOURNAMENT_H
