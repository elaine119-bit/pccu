#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;
class Player {
public:
    Player();
    Player(string name);

    string getName();
    int getAttempts();
    void addAttempt();

private:
    string _name;
    int _attempts;
};
#endif