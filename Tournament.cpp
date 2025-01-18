#include "Tournament.h"
#include "Match.h"
#include <iostream>

void Tournament::simulateTournament(std::vector<Fighter> &fighters) {
    std::vector<Fighter> currentRound = fighters;
    std::vector<Fighter> nextRound;
    Match match;

    int roundNumber = 1;

    while (currentRound.size() > 1) {
        std::cout << "Round " << roundNumber++ << " Matchups:\n";
        for (int i = 0; i < currentRound.size() / 2; ++i) {
            std::cout << currentRound[i].name << " vs " << currentRound[currentRound.size() - 1 - i].name << "\n";
            Fighter winner = match.simulateMatch(currentRound[i], currentRound[currentRound.size() - 1 - i]);
            std::cout << "******************************************************" << std::endl;
            nextRound.push_back(winner);
        }

        currentRound = nextRound;
        nextRound.clear();
        std::cout << "\n";
    }

    if (!currentRound.empty()) {
        std::cout << "The tournament winner is: " << currentRound[0].name << "!\n\n";
        std::cout << "******************************************************\n" << std::endl;
    }
}