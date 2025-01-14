#include "fighters.h"

std::vector<Fighter> HW;
std::vector<Fighter> LHW;
std::vector<Fighter> MW;
std::vector<Fighter> WW;
std::vector<Fighter> LW;
std::vector<Fighter> FW;
std::vector<Fighter> BW;
std::vector<Fighter> FLW;

void populateFighters(){
    HW.emplace_back("Jon Jones", "USA", 1, 95, 92, 94);
    HW.emplace_back("Tom Aspinall", "UK", 2, 92, 90, 89);
    HW.emplace_back("Ciryl Gane", "France", 3, 94, 70, 88);
    HW.emplace_back("Alexander Volkov", "Russia", 4, 91, 65, 86);
    HW.emplace_back("Sergei Pavlovich", "Russia", 5, 93, 60, 87);
    HW.emplace_back("Curtis Blaydes", "USA", 6, 85, 92, 88);
    HW.emplace_back("Jailton Almeida", "Brazil", 7, 78, 95, 85);
    HW.emplace_back("Serghei Spivac", "Moldova", 8, 83, 90, 84);
    HW.emplace_back("Marcin Tybura", "Poland", 9, 80, 85, 83);
    HW.emplace_back("Jairzinho Rozenstruik", "Suriname", 10, 88, 60, 82);
    HW.emplace_back("Derrick Lewis", "USA", 11, 90, 58, 80);
    HW.emplace_back("Tai Tuivasa", "Australia", 12, 87, 55, 78);
    HW.emplace_back("Marcos Rogerio de Lima", "Brazil", 13, 82, 70, 79);
    HW.emplace_back("Waldo Cortes Acosta", "Dominican Republic", 14, 81, 68, 77);
    HW.emplace_back("Shamil Gaziev", "Russia", 15, 79, 66, 76);
    HW.emplace_back("Mick Parkin", "UK", 16, 78, 65, 75);

    // Light Heavyweight
    LHW.emplace_back("Alex Pereira", "Brazil", 1, 96, 82, 94);
    LHW.emplace_back("Magomed Ankalaev", "Russia", 2, 88, 92, 90);
    LHW.emplace_back("Jiri Prochazka", "Czech Republic", 3, 94, 78, 93);
    LHW.emplace_back("Jamahal Hill", "USA", 4, 89, 75, 91);
    LHW.emplace_back("Jan Blachowicz", "Poland", 5, 85, 82, 90);
    LHW.emplace_back("Aleksandar Rakic", "Austria", 6, 83, 86, 87);
    LHW.emplace_back("Carlos Ulberg", "New Zealand", 7, 84, 80, 85);
    LHW.emplace_back("Khalil Rountree Jr.", "USA", 8, 88, 65, 84);
    LHW.emplace_back("Nikita Krylov", "Ukraine", 9, 82, 85, 83);
    LHW.emplace_back("Volkan Oezdemir", "Switzerland", 10, 86, 70, 82);
    LHW.emplace_back("Johnny Walker", "Brazil", 11, 85, 73, 81);
    LHW.emplace_back("Dominick Reyes", "USA", 12, 84, 70, 79);
    LHW.emplace_back("Azamat Murzakanov", "Russia", 13, 78, 80, 78);
    LHW.emplace_back("Bogdan Guskov", "Uzbekistan", 14, 76, 75, 77);
    LHW.emplace_back("Anthony Smith", "USA", 15, 80, 78, 76);
    LHW.emplace_back("Alonzo Menifield", "USA", 16, 78, 77, 75);

    // Middleweight
    MW.emplace_back("Dricus Du Plessis", "South Africa", 1, 84, 93, 92);
    MW.emplace_back("Sean Strickland", "USA", 2, 88, 91, 90);
    MW.emplace_back("Israel Adesanya", "Nigeria", 3, 97, 75, 93);
    MW.emplace_back("Khamzat Chimaev", "Sweden", 4, 84, 96, 92);
    MW.emplace_back("Robert Whittaker", "Australia", 5, 92, 82, 89);
    MW.emplace_back("Nassourdine Imavov", "France", 6, 86, 85, 85);
    MW.emplace_back("Caio Borralho", "Brazil", 7, 78, 90, 83);
    MW.emplace_back("Marvin Vettori", "Italy", 8, 81, 88, 85);
    MW.emplace_back("Jared Cannonier", "USA", 9, 85, 70, 83);
    MW.emplace_back("Brendan Allen", "USA", 10, 79, 87, 82);
    MW.emplace_back("Roman Dolidze", "Georgia", 11, 80, 90, 81);
    MW.emplace_back("Paulo Costa", "Brazil", 12, 86, 75, 80);
    MW.emplace_back("Jack Hermansson", "Sweden", 13, 78, 85, 79);
    MW.emplace_back("Anthony Hernandez", "USA", 14, 76, 83, 78);
    MW.emplace_back("Shara Magomedov", "Russia", 15, 75, 82, 77);
    MW.emplace_back("Michel Pereira", "Brazil", 16, 80, 80, 78);


    // Welterweight
    WW.emplace_back("Belal Muhammad", "USA", 1, 83, 95, 92);
    WW.emplace_back("Leon Edwards", "UK", 2, 90, 91, 93);
    WW.emplace_back("Shavkat Rakhmonov", "Kazakhstan", 3, 89, 90, 94);
    WW.emplace_back("Kamaru Usman", "Nigeria", 4, 85, 94, 91);
    WW.emplace_back("Jack Della Maddalena", "Australia", 5, 92, 70, 88);
    WW.emplace_back("Sean Brady", "USA", 6, 82, 93, 85);
    WW.emplace_back("Joaquin Buckley", "USA", 7, 88, 80, 83);
    WW.emplace_back("Ian Machado Garry", "Ireland", 8, 86, 82, 84);
    WW.emplace_back("Gilbert Burns", "Brazil", 9, 87, 85, 83);
    WW.emplace_back("Colby Covington", "USA", 10, 82, 90, 87);
    WW.emplace_back("Geoff Neal", "USA", 11, 84, 82, 82);
    WW.emplace_back("Stephen Thompson", "USA", 12, 91, 60, 85);
    WW.emplace_back("Michael Morales", "Ecuador", 13, 80, 88, 81);
    WW.emplace_back("Carlos Prates", "Brazil", 14, 77, 85, 79);
    WW.emplace_back("Vicente Luque", "Brazil", 15, 82, 83, 82);
    WW.emplace_back("Michael Page", "UK", 16, 94, 65, 81);

    // Lightweight
    LW.emplace_back("Islam Makhachev", "Russia", 1, 88, 97, 96);
    LW.emplace_back("Arman Tsarukyan", "Armenia", 2, 85, 91, 88);
    LW.emplace_back("Charles Oliveira", "Brazil", 3, 89, 85, 91);
    LW.emplace_back("Justin Gaethje", "USA", 4, 93, 60, 88);
    LW.emplace_back("Dustin Poirier", "USA", 5, 92, 65, 87);
    LW.emplace_back("Max Holloway", "USA", 6, 94, 70, 85);
    LW.emplace_back("Dan Hooker", "New Zealand", 7, 86, 80, 84);
    LW.emplace_back("Michael Chandler", "USA", 8, 87, 88, 82);
    LW.emplace_back("Mateusz Gamrot", "Poland", 9, 84, 90, 83);
    LW.emplace_back("Beneil Dariush", "Iran", 10, 83, 93, 84);
    LW.emplace_back("Renato Moicano", "Brazil", 11, 80, 87, 80);
    LW.emplace_back("Rafael Fiziev", "Azerbaijan", 12, 89, 60, 85);
    LW.emplace_back("Benoit Saint Denis", "France", 13, 78, 83, 79);
    LW.emplace_back("Paddy Pimblett", "UK", 14, 75, 70, 78);
    LW.emplace_back("Jalin Turner", "USA", 15, 77, 73, 76);
    LW.emplace_back("Joel Alvarez", "Spain", 16, 74, 68, 74);

    // Featherweight
    FW.emplace_back("Ilia Topuria", "Spain", 1, 94, 88, 92);
    FW.emplace_back("Alexander Volkanovski", "Australia", 2, 95, 90, 94);
    FW.emplace_back("Max Holloway", "USA", 3, 93, 85, 91);
    FW.emplace_back("Diego Lopes", "Brazil", 4, 85, 88, 86);
    FW.emplace_back("Movsar Evloev", "Russia", 5, 84, 90, 89);
    FW.emplace_back("Yair Rodriguez", "Mexico", 6, 91, 75, 87);
    FW.emplace_back("Brian Ortega", "USA", 7, 83, 92, 86);
    FW.emplace_back("Arnold Allen", "UK", 8, 86, 85, 84);
    FW.emplace_back("Josh Emmett", "USA", 9, 88, 78, 82);
    FW.emplace_back("Aljamain Sterling", "USA", 10, 80, 93, 85);
    FW.emplace_back("Calvin Kattar", "USA", 11, 87, 82, 83);
    FW.emplace_back("Lerone Murphy", "UK", 12, 84, 80, 80);
    FW.emplace_back("Giga Chikadze", "Georgia", 13, 89, 73, 78);
    FW.emplace_back("Bryce Mitchell", "USA", 14, 82, 87, 77);
    FW.emplace_back("Dan Ige", "USA", 15, 84, 80, 76);
    FW.emplace_back("Edson Barboza", "Brazil", 16, 92, 70, 75);

    // Bantamweight
    BW.emplace_back("Merab Dvalishvili", "Georgia", 1, 85, 96, 90);
    BW.emplace_back("Sean O'Malley", "USA", 2, 94, 78, 88);
    BW.emplace_back("Umar Nurmagomedov", "Russia", 3, 85, 93, 87);
    BW.emplace_back("Petr Yan", "Russia", 4, 89, 87, 85);
    BW.emplace_back("Cory Sandhagen", "USA", 5, 91, 82, 84);
    BW.emplace_back("Deiveson Figueiredo", "Brazil", 6, 88, 85, 82);
    BW.emplace_back("Marlon Vera", "Ecuador", 7, 86, 83, 81);
    BW.emplace_back("Henry Cejudo", "USA", 8, 85, 88, 85);
    BW.emplace_back("Song Yadong", "China", 9, 87, 82, 83);
    BW.emplace_back("Rob Font", "USA", 10, 84, 79, 82);
    BW.emplace_back("Mario Bautista", "USA", 11, 80, 83, 81);
    BW.emplace_back("Jose Aldo", "Brazil", 12, 90, 78, 80);
    BW.emplace_back("Kyler Phillips", "USA", 13, 78, 82, 78);
    BW.emplace_back("Aiemann Zahabi", "Canada", 14, 77, 80, 76);
    BW.emplace_back("Marcus McGhee", "USA", 15, 76, 77, 75);
    BW.emplace_back("Montel Jackson", "USA", 16, 75, 78, 74);

    // Flyweight
    FLW.emplace_back("Alexandre Pantoja", "Brazil", 1, 90, 88, 92);
    FLW.emplace_back("Brandon Royval", "USA", 2, 87, 83, 89);
    FLW.emplace_back("Brandon Moreno", "Mexico", 3, 85, 85, 91);
    FLW.emplace_back("Amir Albazi", "Iraq", 4, 82, 90, 88);
    FLW.emplace_back("Kai Kara-France", "New Zealand", 5, 88, 80, 85);
    FLW.emplace_back("Tatsuro Taira", "Japan", 6, 84, 88, 84);
    FLW.emplace_back("Manel Kape", "Angola", 7, 89, 78, 84);
    FLW.emplace_back("Alex Perez", "USA", 8, 84, 79, 82);
    FLW.emplace_back("Asu Almabaev", "Kazakhstan", 9, 80, 85, 80);
    FLW.emplace_back("Steve Erceg", "Australia", 10, 78, 82, 78);
    FLW.emplace_back("Tim Elliott", "USA", 11, 76, 83, 77);
    FLW.emplace_back("Tagir Ulanbekov", "Russia", 12, 78, 87, 79);
    FLW.emplace_back("Charles Johnson", "USA", 13, 77, 80, 76);
    FLW.emplace_back("Bruno Silva", "Brazil", 14, 75, 78, 75);
    FLW.emplace_back("Kai Asakura", "Japan", 15, 76, 75, 74);
    FLW.emplace_back("Joshua Van", "USA", 16, 74, 73, 72);
}
