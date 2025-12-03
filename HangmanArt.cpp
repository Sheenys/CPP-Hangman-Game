// HangmanArt.cpp
#include "HangmanArt.h"
#include <iostream>
using namespace std;

void drawHangman(int incorrectGuesses) {
    cout << "\nHangman:\n";
    if (incorrectGuesses >= 1) cout << "  O\n"; else cout << "\n";
    if (incorrectGuesses == 2) cout << "  |\n";
    if (incorrectGuesses == 3) cout << " /|\n";
    if (incorrectGuesses >= 4) cout << " /|\\\n";
    if (incorrectGuesses == 5) cout << " / \n";
    if (incorrectGuesses >= 6) cout << " / \\\n";
    cout << endl;
}
