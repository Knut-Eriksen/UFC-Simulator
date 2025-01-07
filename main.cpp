#include <iostream>
#include <string>
#include <vector>


int weightClasses[7] = {135, 145, 155, 170, 185, 205, 255};

class Fighter{
public:
    int ID;
    std::string name;
    std::string gender;
    std::string nationality;
    int ranking;
    int weightClass;
    int striking;
    int groundGame;
    int stamina;

    Fighter(int idInput, std::string nameInput, std::string genderInput, std::string nationalityInput, int rankingInput, int weightClassInput, int strikingInput, int groundGameInput, int staminaInput) {
        ID = idInput;
        name = nameInput;
        gender = genderInput;
        nationality = nationalityInput;
        ranking = rankingInput;
        weightClass = weightClassInput;
        striking = strikingInput;
        groundGame = groundGameInput;
        stamina = staminaInput;
    }
};

class Tournament{
public:




    void seed(){



        std::cout << "Tournament seeded" << "\n";

    }


};

class Match{
public:

    void simluateMatch(){
        std::cout << "Match started" << "\n";
    }



};

class FightCommentary{

};

class UserInterface{

};



int main() {




    Tournament UFC_Tournament;
    UFC_Tournament.seed();


    std::vector<Fighter> HW;

    HW.push_back(Fighter(1, "Jon Jones", "Male", "USA", 1, 255, 95, 92, 94));
    HW.push_back(Fighter(2, "Tom Aspinall", "Male", "UK", 2, 255, 92, 90, 89));
    HW.push_back(Fighter(3, "Ciryl Gane", "Male", "France", 3, 255, 94, 70, 88));
    HW.push_back(Fighter(4, "Alexander Volkov", "Male", "Russia", 4, 255, 91, 65, 86));
    HW.push_back(Fighter(5, "Sergei Pavlovich", "Male", "Russia", 5, 255, 93, 60, 87));
    HW.push_back(Fighter(6, "Curtis Blaydes", "Male", "USA", 6, 255, 85, 92, 88));
    HW.push_back(Fighter(7, "Jailton Almeida", "Male", "Brazil", 7, 255, 78, 95, 85));
    HW.push_back(Fighter(8, "Serghei Spivac", "Male", "Moldova", 8, 255, 83, 90, 84));
    HW.push_back(Fighter(9, "Marcin Tybura", "Male", "Poland", 9, 255, 80, 85, 83));
    HW.push_back(Fighter(10, "Jairzinho Rozenstruik", "Male", "Suriname", 10, 255, 88, 60, 82));
    HW.push_back(Fighter(11, "Derrick Lewis", "Male", "USA", 11, 255, 90, 58, 80));
    HW.push_back(Fighter(12, "Tai Tuivasa", "Male", "Australia", 12, 255, 87, 55, 78));
    HW.push_back(Fighter(13, "Marcos Rogerio de Lima", "Male", "Brazil", 13, 255, 82, 70, 79));
    HW.push_back(Fighter(14, "Waldo Cortes Acosta", "Male", "Dominican Republic", 14, 255, 81, 68, 77));
    HW.push_back(Fighter(15, "Shamil Gaziev", "Male", "Russia", 15, 255, 79, 66, 76));
    HW.push_back(Fighter(16, "Mick Parkin", "Male", "UK", 16, 255, 78, 65, 75));






    return 0;
}
