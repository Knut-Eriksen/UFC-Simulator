#include <vector>
#include "fighters.h"
#include <ctime>
#include "UserInterface.h"

void initRandomNumber(){
    srand(time(NULL));
}

int main() {
    initRandomNumber();
    populateFighters();
    UserInterface UserInterface;
    UserInterface.displayMenu();
    return 0;
}
