#ifndef SECRETNUMBER_H
#define SECRETNUMBER_H

enum class GuessResult {
    Correct,
    TooLow,
    TooHigh
};

class SecretNumber {
public:
    SecretNumber(int low = 1, int high = 100);

    int getLow();
    int getHigh();

    void narrowRange(int guess);
    GuessResult check(int guess);

private:
    int _answer;
    int _low;
    int _high;
};
#endif