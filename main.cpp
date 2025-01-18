#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "fighters.h"
#include <ctime>

void initRandomNumber(){
    srand(time(NULL));
}

class FightCommentary{
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

    int randomNumber(){
        int randomIndex = (rand() % 4) + 0;
        return randomIndex;
    }

    void fightCommentary(Fighter& winner, Fighter& loser) {
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
            commentary.fightCommentary(fighter1, fighter2);
            return fighter1;
        } else {
            commentary.fightCommentary(fighter2, fighter1);
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

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1-3." << std::endl;
            }

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

    std::vector<std::string> weightClasses = {
            "Heavyweight", "Light Heavyweight", "Middleweight",
            "Welterweight", "Lightweight", "Featherweight",
            "Bantamweight", "Flyweight"
    };

    void chooseWeightSimulation(Tournament& UFCTournament) {
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
        int weightClass;
        do {
            std::cout << "Choose a weight class to view fighter stats.\n";
            for (int i = 0; i < weightClasses.size(); ++i) {
                std::cout << i + 1 << ". " << weightClasses[i] << std::endl;
            }
            std::cout << "Enter the number of the weight or '9' to Exit: ";
            std::cin >> weightClass;

            switch (weightClass) {
                case 1:
                    Fighter::displayWeightClassStats(HW);
                    break;
                case 2:
                    Fighter::displayWeightClassStats(LHW);
                    break;
                case 3:
                    Fighter::displayWeightClassStats(MW);
                    break;
                case 4:
                    Fighter::displayWeightClassStats(WW);
                    break;
                case 5:
                    Fighter::displayWeightClassStats(LW);
                    break;
                case 6:
                    Fighter::displayWeightClassStats(FW);
                    break;
                case 7:
                    Fighter::displayWeightClassStats(BW);
                    break;
                case 8:
                    Fighter::displayWeightClassStats(FLW);
                    break;
                case 9:
                    break;
                default:
                    break;
            }
        }while(weightClass != 9);
    }
};

int main() {
    initRandomNumber();
    populateFighters();
    UserInterface UserInterface;
    UserInterface.displayMenu();
    return 0;
}
