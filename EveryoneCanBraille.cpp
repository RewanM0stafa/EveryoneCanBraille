//
// Created by rodlv on 12/16/2024.
//
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long
#define loop(n) for (ll i = 0; i < n; i++)

const char* braille[26] = {
    "000001", "000101", "000011", "001011", "001001",
    "000111", "001111", "001101", "000110", "001110",
    "010001", "010101", "010011", "011011", "011001",
    "010111", "011111", "011101", "010110", "011110",
    "110001", "110101", "101110", "110011", "111011", "111001"
};

// Print all the alphabet letters in Braille
void braille_AllLetters() {
    for (int i = 0; i < 26; i++) {
        char c = 'A' + i;
        cout << c << " -> \n";
        for (int row = 2; row >= 0; row--) {
            if (braille[i][row * 2 + 1] == '1') cout << "⠁";
            else cout << " ";
            if (braille[i][row * 2] == '1') cout << "⠁";
            else cout << " ";
            cout << "\n";
        }
    }
}

// Convert a single letter into Braille
void braille_Letter(char c) {
    c = char(toupper(c));
    for (int row = 2; row >= 0; row--) {
        if (braille[c - 'A'][row * 2 + 1] == '1') cout << "⠁";
        else cout << " ";
        if (braille[c - 'A'][row * 2] == '1') cout << "⠁";
        else cout << " ";
        cout << "\n";
    }
}

// Convert a word into Braille
void braille_Word(string word) {
    for (int row = 2; row >= 0; row--) {
        for (int i = 0; i < word.size(); i++) {
            word[i] = char(toupper(word[i]));
            int index = word[i] - 'A';

            if (braille[index][row * 2 + 1] == '1') cout << "⠁";
            else cout << " ";
            if (braille[index][row * 2] == '1') cout << "⠁";
            else cout << " ";
            cout << "  "; // Space between letters
        }
        cout << endl;
    }
}

// Generate a random number between 0 and 25 for the quiz
int generateRandomNumber() {
    static bool isSeeded = false;
    if (!isSeeded) {
        srand(static_cast<unsigned int>(time(0)));
        isSeeded = true;
    }
    return rand() % 26;
}

// Quiz the user by showing Braille and asking them to guess the letter
void Quiz(int q) {
    int score = 0;
    cout << "Guess the character: \n\n";
    while (q--) {
        char c = char(generateRandomNumber() + 'A');
        braille_Letter(c);

        cout << "Your answer is: ";
        char b;
        cin >> b;
        b = char(toupper(b));

        if (b == c) {
            score += 5;
            cout << "\nCorrect! \n\n";
        } else {
            if (score >= 5) score -= 5;
            else score = 0;
            cout << "\nIncorrect! The correct answer was: " << c << "\n\n";
        }
    }
    cout << "Your score now is: " << score << "\n";
}

int main() {
    cout << "Hello! Hope you're doing great! :) \n"
         << "Welcome to the Braille learning program – let's make learning fun and easy! 🌟\n";

    while (true) {
        cout << "1. Print all alphabets in Braille.\n"
             << "2. Translate a letter into Braille.\n"
             << "3. Translate a word into Braille.\n"
             << "4. Quiz.\n";
        cout << "Choose a num: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                braille_AllLetters();
                break;
            }

            case 2: {
                cout << "Enter a character: ";
                char c1;
                cin >> c1;
                braille_Letter(c1);
                break;
            }

            case 3: {
                cout << "Enter a word: ";
                string word;
                cin >> word;
                braille_Word(word);
                break;
            }

            case 4: {
                cout << "How many questions do you want? -> ";
                int q;
                cin >> q;
                Quiz(q);
                break;
            }

            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }

        cout << "\nDo you want to continue? \n -Yes/y \t -No/n \n";
        string ans;
        cout<<"->";
        cin >> ans;
        if (ans[0] == 'n' || ans[0] == 'N') {
            cout << "Great job today! Keep learning and take care! \n Goodbye! ^^ \n";
            break;
        }
    }

    return 0;
}
