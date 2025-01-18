#include "Match.h"
#include "FightCommentary.h"

Fighter Match::simulateMatch(Fighter& fighter1, Fighter& fighter2) {
    FightCommentary commentary;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-5, 5);

    float fighter1OverallScore = fighter1.striking * 0.5 + fighter1.grappling * 0.3 + fighter1.stamina * 0.2 + dist(gen);
    float fighter2OverallScore = fighter2.striking * 0.5 + fighter2.grappling * 0.3 + fighter2.stamina * 0.2 + dist(gen);

    if (fighter1OverallScore > fighter2OverallScore) {
        commentary.fightCommentary(fighter1, fighter2);
        return fighter1;
    } else {
        commentary.fightCommentary(fighter2, fighter1);
        return fighter2;
    }
}