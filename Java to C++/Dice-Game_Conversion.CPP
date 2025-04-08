#include <iostream>
#include <cstdlib>
#include <ctime>
 
using namespace std;

int main() {
    srand(time(0));
    
    char repe;
    
    do {

        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        
        cout << "\nDice Rolling Simulation\n\n";

        cout << "Dice Result 1: " << dice1 << "\n";
        cout << "Dice Result 2: " << dice2 << "\n";

        cout << "Total: " << (dice1 + dice2) << "\n";
        
        cout << "\nRoll Again? \ny/n: ";
        cin >> repe;

    }
    while (repe == 'Y' || repe == 'y');
    
    return 0;

}
