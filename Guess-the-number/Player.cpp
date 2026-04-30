#include "Player.h"
using namespace std;
Player::Player(){
    _name="";
    _attempts=0;
}
Player::Player(string name){
    _name=name;
    _attempts=0;
}
string Player::getName(){ return _name;}
int Player::getAttempts(){ return _attempts; }

void Player::addAttempt() {
    _attempts++;
}