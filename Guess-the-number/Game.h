#ifndef GAME_H
#define GAME_H
#include "SecretNumber.h"
#include "Player.h"
#include <string>
using namespace std;
class Game {
public:
    Game(string playerName, int low = 1, int high = 100);

    void play();

private:
    SecretNumber _secret;
    Player _player;

    int  getValidInput();
    void printBanner();
    void printResult();
};
#endif