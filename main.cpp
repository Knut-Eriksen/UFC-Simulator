#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cctype>
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
    int tournamentId;
    std::string name;

    Tournament(int tournamentId, const std::string& name) : tournamentId(tournamentId), name(name) {}

    void simulateTournament(std::vector<Fighter> &fighters){
        std::vector<Fighter> currentRound;
        std::vector<Fighter> nextRound;
        Match match;
        std::cout << "\nThe first round match ups are:" << "\n";

        int weightClassSize = fighters.size();
        for (int i = 0; i < weightClassSize / 2; ++i) {
            std::cout << fighters[i].name << " vs " << fighters[weightClassSize - 1 - i].name << "\n";

            currentRound.push_back(fighters[i]);
            currentRound.push_back(fighters[weightClassSize - 1 - i]);
        }

        std::cout << "\n";

        while (currentRound.size() > 1) {
            for (int i = 0; i < currentRound.size(); i += 2) {
                int currentRoundSize = currentRound.size();
                Fighter winner = match.simulateMatch(currentRound[i], currentRound[currentRoundSize - 1 - i]);
                nextRound.push_back(winner);
            }

            currentRound = nextRound;
            nextRound.clear();
            std::cout << "\n";
        }
    }


};

std::vector<Tournament> saveFiles;



class UserInterface {
public:


    void displayMenu() {
        int choice;

        do {
            std::cout << "******************** UFC-Simulator ********************\n";
            std::cout << "1. Start a Tournament\n";
            std::cout << "2. Load Tournament\n";
            std::cout << "3. View Fighter Stats\n";
            std::cout << "4. Exit\n";
            std::cout << "******************************************************\n";
            std::cout << "Please enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    startTournament();
                    break;
                case 2:
                    loadTournament(saveFiles);
                    break;
                case 3:
                    chooseweighClass();
                    break;

            }
        }while(choice != 3);

    }

    void loadTournament(std::vector<Tournament> &saveFiles){
        for (int i = 0; i < saveFiles.size(); ++i) {
            std::cout << saveFiles[i].tournamentId << ". " << saveFiles[i].name << "\n";
        }
    }

    void startTournament() {
        int tournamentCount = 0;
        std::string tournamentName;
        std::cout << "Enter a tournament name: ";
        std::cin.ignore();
        std::getline(std::cin >> std::ws, tournamentName);
        tournamentCount += 1;

        Tournament UFCTournament(tournamentCount, tournamentName);
        saveFiles.push_back(UFCTournament);
        chooseWeightSimulation(UFCTournament);
    }

    void chooseWeightSimulation(Tournament& UFCTournament){
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
                UFCTournament.simulateTournament(HW);
            } else if (weightClass == "LHW"){
                UFCTournament.simulateTournament(LHW);
            }else if (weightClass == "MW"){
                UFCTournament.simulateTournament(MW);
            }else if (weightClass == "WW"){
                UFCTournament.simulateTournament(WW);
            }else if (weightClass == "LW"){
                UFCTournament.simulateTournament(LW);
            }else if (weightClass == "BW"){
                UFCTournament.simulateTournament(BW);
            }else if (weightClass == "FLW"){
                UFCTournament.simulateTournament(FLW);
            }
        }while(weightClass != "EXIT");
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
