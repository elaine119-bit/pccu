#include "Game.h"
#include <iostream>
using namespace std;
Game::Game(string playerName, int low, int high){
    _secret=SecretNumber(low,high);
    _player=Player(playerName);
}

void Game::printBanner() {
    cout << "========================================\n";
    cout << "       Ultimate Password Game!\n";
    cout << "  Range: " << _secret.getLow()
              << " ~ " << _secret.getHigh() << "\n";
    cout << "========================================\n";
}

void Game::printResult() {
    cout << "\nCongrats " << _player.getName() << "! You got it!\n";
    cout << "Total guesses: " << _player.getAttempts() << "\n";
    cout << "========================================\n";
    cout << "Game Over. Thanks for playing!\n";
    cout << "========================================\n";
}

int Game::getValidInput() {
    int value;
    while (true) {
        cout << "Enter a number ("
                  << _secret.getLow() << " ~ " << _secret.getHigh() << "): ";
        if (cin >> value) {
            if (value >= _secret.getLow() && value <= _secret.getHigh())
                return value;
            cout << "  Out of range! Try again.\n";
        } else {
            cout << "  Invalid input!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

void Game::play() {
    printBanner();

    bool won = false;
    while (!won) {
        int guess = getValidInput();
        _player.addAttempt();

        GuessResult result = _secret.check(guess);
        _secret.narrowRange(guess);

        switch (result) {
        case GuessResult::Correct:
            cout << "  *** Correct! The answer is " << guess << "! ***\n";
            won = true;
            break;
        case GuessResult::TooLow:
            cout << "  Too low!  New range: "
                      << _secret.getLow() << " ~ " << _secret.getHigh() << "\n";
            break;
        case GuessResult::TooHigh:
            cout << "  Too high! New range: "
                      << _secret.getLow() << " ~ " << _secret.getHigh() << "\n";
            break;
        }
    }

    printResult();
}
