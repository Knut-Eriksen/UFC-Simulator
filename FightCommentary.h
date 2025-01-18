#ifndef UFC_SIMULATOR_FIGHTCOMMENTARY_H
#define UFC_SIMULATOR_FIGHTCOMMENTARY_H

#include "fighters.h"


class FightCommentary {
public:

    std::vector<std::string> closeFight = {
            "gave it their all, leaving everything in the cage, and emerged victorious.",
            "fought in a razor-thin battle, with neither willing to back down, but secured the win.",
            "exchanged blow for blow in an even contest and managed to edge out the victory.",
            "kept the crowd on the edge of their seats in a dead-even fight and came out on top.",
            "traded strikes evenly in an incredible contest but found a way to secure the win.",
            "battled through an evenly matched fight, leaving the judges with a tough decision, but took the victory."
    };

    std::vector<std::string> strikingAdvantage = {
            "landed some crisp strikes, overwhelming.",
            "displayed precision with their striking, landing clean shots.",
            "kept their opponent at bay with sharp jabs and powerful hooks.",
            "unleashed a flurry of punches that left their opponent reeling.",
            "used their superior striking to dictate the pace of the fight.",
            "connected with a devastating uppercut that changed the momentum."
    };

    std::vector<std::string> grapplingAdvantage = {
            "showcased superior grappling, controlling the fight on the ground.",
            "dominated with takedowns and top control.",
            "secured a beautiful double-leg takedown and maintained control.",
            "demonstrated excellent submission attempts, keeping the opponent defensive.",
            "used their grappling to neutralize the opponent's striking.",
            "maintained dominant position throughout the round, exhausting their opponent."
    };

    std::vector<std::string> staminaAdvantage = {
            "looked fresher as the fight progressed, pushing the pace relentlessly.",
            "capitalized on their superior conditioning to outlast their opponent.",
            "showed no signs of fatigue, outworking their opponent in the later rounds.",
            "pressed forward with endless energy, breaking their opponent's will.",
            "kept up a high pace, wearing their opponent down with constant pressure.",
            "demonstrated superior endurance, maintaining control throughout the fight."
    };

    std::vector<std::string> underdog = {
            "defied the odds with a stunning performance and emerged victorious, shocking everyone.",
            "overcame adversity to put on a career-defining fight and claimed a hard-fought win.",
            "proved the doubters wrong by delivering a breathtaking upset victory and taking home the win.",
            "showed heart and determination, turning the tide in their favor to secure the triumph.",
            "displayed resilience, refusing to back down and ultimately defeating a tough opponent.",
            "pulled off an incredible upset, winning the fight and leaving the audience in awe."
    };

    int randomNumber();
    void fightCommentary(Fighter& winner, Fighter& loser);
};

#endif //UFC_SIMULATOR_FIGHTCOMMENTARY_H
