#include <iostream>
#include <string>
#include "Stacks.h"
using namespace std;

void initializeGame(string &word, int &lives) {
    cout << "Enter the word to guess: ";
    cin >> word;
    lives = 6;
}

void displayGameState(const string &word, int lives, const Stack &wrong) {
    cout << "\nWord: ";
    for (char c : word) {
        cout << c << " ";
    }
    cout << "\nIncorrect guesses: " << lives << endl;
    wrong.display();
}

bool checkGuess(char guess, const string &secretWord, string &guessedWord, Stack &wrong) {
    bool found = false;

    for (int i = 0; i < secretWord.size(); i++) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
            found = true;
        }
    }

    if (!found) wrong.push(guess);

    return found;
}
