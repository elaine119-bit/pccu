#include <iostream>
#include <string>
#include "Game.h"
#include<sstream>
using namespace std;
int main() {
    string name;
    int low = 1, high = 100;
    string tmp;
    cout << "=== Ultimate Password ===\n";
    cout << "Enter your English name: ";
    getline(cin, name);
    if (name==""){
        name="Player";
    }
    cout << "Set lower bound (Enter = 1): ";
    getline(cin, tmp);
    if(tmp!=""){
        stringstream ss(tmp);
        ss>>low;
    }

    cout << "Set upper bound (Enter = 100): ";
    getline(cin, tmp);
    if (tmp!=""){
        stringstream ss(tmp);
        ss>>high;
    }
    Game game(name, low, high);
    game.play();

    return 0;
}
 
