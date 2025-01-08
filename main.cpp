#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>






class FightCommentary{
};

class UserInterface{
};

int weightClasses[7] = {135, 145, 155, 170, 185, 205, 255};

class Fighter {
public:
    int ID;
    std::string name;
    std::string gender;
    std::string nationality;
    int rank;
    int weightClass;
    int striking;
    int grappling;
    int stamina;

    Fighter(int ID, const std::string& name, const std::string& gender, const std::string& nationality,
            int rank, int weightClass, int striking, int grappling, int stamina)
            : ID(ID), name(name), gender(gender), nationality(nationality),
              rank(rank), weightClass(weightClass), striking(striking), grappling(grappling), stamina(stamina) {}
};

class Match{
public:
    Fighter simulateMatch(Fighter& fighter1, Fighter& fighter2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(-10, 10);

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
        std::cout << "Fighters seeded by this ranking:\n";
        for (const auto& fighter : fighters) {
            std::cout << fighter.rank << ". " << fighter.name << "\n";
        }

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
        std::vector<Fighter> HW;

        HW.emplace_back(1, "Jon Jones", "Male", "USA", 1, 255, 95, 92, 94);
        HW.emplace_back(2, "Tom Aspinall", "Male", "UK", 2, 255, 92, 90, 89);
        HW.emplace_back(3, "Ciryl Gane", "Male", "France", 3, 255, 94, 70, 88);
        HW.emplace_back(4, "Alexander Volkov", "Male", "Russia", 4, 255, 91, 65, 86);
        HW.emplace_back(5, "Sergei Pavlovich", "Male", "Russia", 5, 255, 93, 60, 87);
        HW.emplace_back(6, "Curtis Blaydes", "Male", "USA", 6, 255, 85, 92, 88);
        HW.emplace_back(7, "Jailton Almeida", "Male", "Brazil", 7, 255, 78, 95, 85);
        HW.emplace_back(8, "Serghei Spivac", "Male", "Moldova", 8, 255, 83, 90, 84);
        HW.emplace_back(9, "Marcin Tybura", "Male", "Poland", 9, 255, 80, 85, 83);
        HW.emplace_back(10, "Jairzinho Rozenstruik", "Male", "Suriname", 10, 255, 88, 60, 82);
        HW.emplace_back(11, "Derrick Lewis", "Male", "USA", 11, 255, 90, 58, 80);
        HW.emplace_back(12, "Tai Tuivasa", "Male", "Australia", 12, 255, 87, 55, 78);
        HW.emplace_back(13, "Marcos Rogerio de Lima", "Male", "Brazil", 13, 255, 82, 70, 79);
        HW.emplace_back(14, "Waldo Cortes Acosta", "Male", "Dominican Republic", 14, 255, 81, 68, 77);
        HW.emplace_back(15, "Shamil Gaziev", "Male", "Russia", 15, 255, 79, 66, 76);
        HW.emplace_back(16, "Mick Parkin", "Male", "UK", 16, 255, 78, 65, 75);

        UFC_Tournament.simulateTournament(HW);



        /*
        for (const auto &fighter: HW) {
            std::cout << fighter.ID << ", "
                      << fighter.name << ", "
                      << fighter.gender << ", "
                      << fighter.nationality << ", "
                      << fighter.rank << ", "
                      << fighter.weightClass << ", "
                      << fighter.striking << ", "
                      << fighter.grappling << ", "
                      << fighter.stamina << std::endl;
        }
*/
        return 0;
    }
