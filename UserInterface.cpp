#include "UserInterface.h"

void UserInterface::displayMenu() {
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

void UserInterface::startTournament() {
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

void UserInterface::chooseWeightSimulation(Tournament& UFCTournament) {
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

void UserInterface::chooseweighClass(){
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