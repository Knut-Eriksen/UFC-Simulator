#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cctype>
#include "fighters.h"

class FightCommentary{
public:

    std::vector<std::string> closeFight = {
            "Both fighters are giving it their all, leaving everything in the cage.",
            "It's a razor-thin battle, with neither fighter willing to back down.",
            "Every exchange is met with an answer; this is anyone's fight to win.",
            "The crowd is on the edge of their seats as the fight remains dead even.",
            "Both fighters are trading blow for blow, refusing to give an inch.",
            "What an evenly matched contest; the judges will have a tough decision here."
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
            "defied the odds with a stunning performance, shocking everyone.",
            "overcame adversity to put on a career-defining fight.",
            "proved the doubters wrong, delivering a breathtaking upset victory.",
            "showed heart and determination, turning the tide in their favor.",
            "displayed resilience, refusing to back down against a tough opponent.",
            "pulled off an incredible upset, leaving the audience in awe."
    };

    std::vector<std::string> favourite = {
            "lived up to expectations with a dominant display.",
            "showcased why they were the favorite, controlling the fight effortlessly.",
            "delivered a clinical performance, leaving no doubt about their skill level.",
            "proved their class with an impressive and well-rounded showing.",
            "executed their game plan perfectly, securing a decisive victory.",
            "demonstrated their superior skill set, dominating every aspect of the fight."
    };


    std::vector<std::string> commentary = {
            "A thunderous right hand lands!",
            "What a takedown! The crowd goes wild!",
            "A beautifully timed counter!",
            "The stamina of these fighters is being pushed to the limit.",
            "A brutal exchange in the center of the cage!",
            "An explosive head kick nearly ends the fight!"
    };

    void fightCommentary(Fighter& winner, Fighter& loser){
        std::string comment;




    }


};

class Match{
public:

    Fighter simulateMatch(Fighter& fighter1, Fighter& fighter2) {
        FightCommentary commentary;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(-5, 5);

        float fighter1OverallScore = fighter1.striking * 0.5 + fighter1.grappling * 0.3 + fighter1.stamina * 0.2 + dist(gen);
        float fighter2OverallScore = fighter2.striking * 0.5 + fighter2.grappling * 0.3 + fighter2.stamina * 0.2 + dist(gen);

        if (fighter1OverallScore > fighter2OverallScore) {
            std::cout << fighter1.name << " defeats " << fighter2.name << "!\n";

            commentary.fightCommentary(fighter1, fighter2);
            return fighter1;
        } else {
            commentary.fightCommentary(fighter2, fighter1);
            std::cout << fighter2.name << " defeats " << fighter1.name << "!\n";

            return fighter2;
        }
    }
};


class Tournament {
public:
    int tournamentId;
    std::string name;

    Tournament(int tournamentId, const std::string& name) : tournamentId(tournamentId), name(name) {}

    void simulateTournament(std::vector<Fighter>& fighters) {
        std::vector<Fighter> currentRound = fighters;
        std::vector<Fighter> nextRound;
        Match match;

        int roundNumber = 1;

        while (currentRound.size() > 1) {
            std::cout << "Round " << roundNumber++ << " Matchups:\n";
            for (int i = 0; i < currentRound.size() / 2; ++i) {
                std::cout << currentRound[i].name << " vs " << currentRound[currentRound.size() - 1 - i].name << "\n";
                Fighter winner = match.simulateMatch(currentRound[i], currentRound[currentRound.size() - 1 - i]);
                nextRound.push_back(winner);
            }

            currentRound = nextRound;
            nextRound.clear();
            std::cout << "\n";
        }

        if (!currentRound.empty()) {
            std::cout << "The tournament winner is: " << currentRound[0].name << "!\n";
        }
    }



};


class UserInterface {
public:
    void displayMenu() {
        int choice;

        do {
            std::cout << "******************** UFC-Simulator ********************" << std::endl;
            std::cout << "1. Start a Tournament" << std::endl;
            std::cout << "2. View Fighter Stats" << std::endl;
            std::cout << "3. Exit" << std::endl;
            std::cout << "******************************************************" << std::endl;
            std::cout << "Please enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    startTournament();
                    break;
                case 2:
                    chooseweighClass();
                    break;
            }
        } while (choice != 3);
    }

    void startTournament() {
        int tournamentCount = 0;
        std::string tournamentName;
        std::cout << "Enter a tournament name: ";
        std::getline(std::cin >> std::ws, tournamentName);
        std::cout << "******************************************************" << std::endl;
        tournamentCount += 1;

        Tournament UFCTournament(tournamentCount, tournamentName);
        chooseWeightSimulation(UFCTournament);
    }

    void chooseWeightSimulation(Tournament& UFCTournament) {
        std::vector<std::string> weightClasses = {
                "Heavyweight", "Light Heavyweight", "Middleweight",
                "Welterweight", "Lightweight", "Featherweight",
                "Bantamweight", "Flyweight"
        };

        std::vector<bool> simulated(weightClasses.size(), false);

        int choice = 0;

        while(true){
            std::cout << "Choose a weight to simulate." << std::endl;
            for (int i = 0; i < weightClasses.size(); ++i) {
                std::cout << i + 1 << ". " << weightClasses[i] << (simulated[i] ? " (Already simulated)" : "") << std::endl;
            }
            std::cout << "Enter the number of the weight class you want to simulate or '9' to Exit: ";
            std::cin >> choice;

            if (choice == 9) {
                std::cout << "\nExiting simulation. Thank you!\n";
                break;
            }

             else if (!simulated[choice - 1]){
                switch (choice) {
                    case 1:
                        UFCTournament.simulateTournament(HW);
                        simulated[choice - 1] = true;
                        break;
                    case 2:
                        UFCTournament.simulateTournament(LHW);
                        simulated[choice - 1] = true;
                        break;
                    case 3:
                        UFCTournament.simulateTournament(MW);
                        simulated[choice - 1] = true;
                        break;
                    case 4:
                        UFCTournament.simulateTournament(WW);
                        simulated[choice - 1] = true;
                        break;
                    case 5:
                        UFCTournament.simulateTournament(LW);
                        simulated[choice - 1] = true;
                        break;
                    case 6:
                        UFCTournament.simulateTournament(FW);
                        simulated[choice - 1] = true;
                        break;
                    case 7:
                        UFCTournament.simulateTournament(BW);
                        simulated[choice - 1] = true;
                        break;
                    case 8:
                        UFCTournament.simulateTournament(FLW);
                        simulated[choice - 1] = true;
                        break;
                    case 9:
                        break;
                    default:
                        break;
                }
            }else {
                std::cout << std::endl << "You have already simulated this weight class. Go check out the results in the result tab." << std::endl << std::endl;
            }
        }
    }


    void chooseweighClass(){
        std::string weightClass;

        do {
            std::cout << "Choose a weight class to view fighter stats.\n";
            std::cout << "HW. Heavyweight\n";
            std::cout << "LHW. Heavyweight\n";
            std::cout << "MW. Heavyweight\n";
            std::cout << "WW. Heavyweight\n";
            std::cout << "LW. Heavyweight\n";
            std::cout << "FW. Heavyweight\n";
            std::cout << "BW. Heavyweight\n";
            std::cout << "FLW. Heavyweight\n";
            std::cout << "FLW. Heavyweight\n";
            std::cout << "Enter weight class in format of 'HW' or Exit: ";
            std::getline(std::cin >> std::ws, weightClass);

            for (char& ch : weightClass) {
                ch = toupper(ch);
            }
            if (weightClass == "HW"){
                Fighter::displayWeightClassStats(HW);
            } else if (weightClass == "LHW"){
                Fighter::displayWeightClassStats(LHW);
            }else if (weightClass == "MW"){
                Fighter::displayWeightClassStats(MW);
            }else if (weightClass == "WW"){
                Fighter::displayWeightClassStats(WW);
            }else if (weightClass == "LW"){
                Fighter::displayWeightClassStats(LW);
            }else if (weightClass == "BW"){
                Fighter::displayWeightClassStats(BW);
            }else if (weightClass == "FLW"){
                Fighter::displayWeightClassStats(FLW);
            }
        }while(weightClass != "EXIT");
    }
};

int main() {
    populateFighters();
    UserInterface UserInterface;
    UserInterface.displayMenu();

    return 0;
}
