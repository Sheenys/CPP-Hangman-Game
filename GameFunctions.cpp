#include <iostream>
#include <string>
#include "Stacks.h"
#include "HangmanArt.h"   // New hangman drawing
using namespace std;

// Initialize game: get secret word and set lives
void initializeGame(string &word, int &lives) {
    cout << "Enter the word to guess: ";
    cin >> word;
    for (char &c : word) c = toupper(c); // Convert word to uppercase
    lives = 6;
}

// Display current game state
void displayGameState(const string &guessedWord, int lives, const Stack &wrong) {
    drawHangman(6 - lives);  // Draw hangman depending on wrong guesses
    cout << "\nWord: ";
    for (char c : guessedWord) {
        cout << c << " ";
    }
    cout << "\nIncorrect guesses left: " << lives << endl;
    cout << "Wrong letters: ";
    wrong.display();
    cout << endl;
}

// Check if the guessed letter is in the word
bool checkGuess(char guess, const string &secretWord, string &guessedWord, Stack &wrong) {
    bool found = false;

    for (int i = 0; i < secretWord.size(); i++) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
            found = true;
        }
    }

    if (!found) wrong.push(guess); // Add wrong guess to stack

    return found;
}
