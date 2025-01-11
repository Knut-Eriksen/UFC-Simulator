#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "fighters.h"

class FightCommentary{
};

class Match{
public:
    Fighter simulateMatch(Fighter& fighter1, Fighter& fighter2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(-5, 5);

        float fighter1OverallScore = fighter1.striking * 0.5 + fighter1.grappling * 0.3 + fighter1.stamina * 0.2 + dist(gen);
        float fighter2OverallScore = fighter2.striking * 0.5 + fighter2.grappling * 0.3 + fighter2.stamina * 0.2 + dist(gen);

        if (fighter1OverallScore > fighter2OverallScore) {
            std::cout << fighter1.name << " defeats " << fighter2.name << "!\n";
            return fighter1;
        } else {
            std::cout << fighter2.name << " defeats " << fighter1.name << "!\n";
            return fighter2;
        }
    }
};

class Tournament {
public:

    void simulateTournament(std::vector<Fighter> &fighters){
        std::vector<Fighter> currentRound;
        std::vector<Fighter> nextRound;
        Match match;
        std::cout << "\nThe first round match ups are:" << "\n";

        int n = fighters.size();
        for (int i = 0; i < n / 2; ++i) {
            std::cout << fighters[i].name << " vs " << fighters[n - 1 - i].name << "\n";

            currentRound.push_back(fighters[i]);
            currentRound.push_back(fighters[n - 1 - i]);
        }

        std::cout << "\n";

        while (currentRound.size() > 1) {
            for (int i = 0; i < currentRound.size(); i += 2) {
                Fighter winner = match.simulateMatch(currentRound[i], currentRound[i + 1]);
                nextRound.push_back(winner);
            }

            currentRound = nextRound;
            nextRound.clear();
            std::cout << "\n";
        }
    }
};

int main() {
    Tournament UFC_Tournament;
    populateFighters();

    std::cout << "******************** UFC-Simulator ********************\n";

    UFC_Tournament.simulateTournament(LW);

    return 0;
}
