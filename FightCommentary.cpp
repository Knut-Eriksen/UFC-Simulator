#include "FightCommentary.h"

int FightCommentary::randomNumber(){
    int randomIndex = (rand() % 4) + 0;
    return randomIndex;
}

void FightCommentary::fightCommentary(Fighter& winner, Fighter& loser) {
    int strikingDifference = winner.striking - loser.striking;
    int grapplingDifference = winner.grappling - loser.grappling;
    int staminaDifference = winner.stamina - loser.stamina;

    int largest = std::max({strikingDifference, grapplingDifference, staminaDifference});

    bool isUnderdog = winner.rank > loser.rank;

    if (isUnderdog){
        std::cout << winner.name << " " << underdog[randomNumber()] << std::endl;
    } else if (largest > 9) {
        if (strikingDifference == largest) {
            std::cout << winner.name << " " << strikingAdvantage[randomNumber()] << std::endl;
        } else if (grapplingDifference == largest) {
            std::cout << winner.name << " " << grapplingAdvantage[randomNumber()] << std::endl;
        } else if (staminaDifference == largest) {
            std::cout << winner.name << " " << staminaAdvantage[randomNumber()] << std::endl;
        }
    } else {
        std::cout << winner.name << " " << closeFight[randomNumber()] << std::endl;
    }
}