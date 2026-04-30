#include "SecretNumber.h"
#include <cstdlib>
#include <ctime>

SecretNumber::SecretNumber(int low, int high){
    _low=low;
    _high=high;
    srand(time(NULL));
    _answer=low+rand()%(high-low+1);
}

int SecretNumber::getLow(){return _low;}
int SecretNumber::getHigh(){return _high;}

void SecretNumber::narrowRange(int guess) {
   if (guess < _answer)
    _low  = guess;
else if (guess > _answer)
    _high = guess;
}

GuessResult SecretNumber::check(int guess){
    if (guess == _answer) return GuessResult::Correct;
    if (guess  < _answer) return GuessResult::TooLow;
    return GuessResult::TooHigh;
}