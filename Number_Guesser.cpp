#include <iostream>
#include <stdio.h>
#include <random>
#include <algorithm>
#include <limits>

using namespace std;

void printHeader()
{
    cout << "==========================================" << endl;
    cout << "       *** NUMBER GUESSING GAME ***       " << endl;
    cout << "==========================================" << endl;
    cout << "---- Guess a number between 1 and 10. ----" << endl;
    cout << "---------- You have 20 guesses. ----------" << endl;
    cout << "            ***Good luck!***" << endl;
    cout << "==========================================" << endl;
    cout << endl;
}

void printStatus(int guessesRemaining, int score)
{
    cout << "------------------------------------------" << endl;
    cout << "Guesses Remaining : " << guessesRemaining << endl;
    cout << "Current Score     : " << score << endl;
    cout << "------------------------------------------" << endl;
}

void printCorrect()
{
    cout << endl;
    cout << "Correct!" << endl;
    cout << "A new number has been generated." << endl;
    cout << endl;
}

void printIncorrect()
{
    cout << endl;
    cout << "Incorrect! Try again." << endl;
    cout << endl;
}

void printGameOver(int score)
{
    cout << endl;
    cout << "==========================================" << endl;
    cout << "               GAME OVER" << endl;
    cout << "==========================================" << endl;
    cout << "Final Score : " << score << endl;
    cout << "==========================================" << endl;
}

int generateRandom() {

    random_device rd;
    mt19937 generator(rd());

    uniform_int_distribution<int> distribution(1,10);

    int number = distribution(generator);

    return number;
}

int main() {
    
    int guessNumber;
    int numberOfGuess = 20;
    int playerScore = 0;

    int randomNumber = generateRandom();

    printHeader();

    while(numberOfGuess > 0) {

        printStatus(numberOfGuess, playerScore);

        cout << "Guess a number (1-10): ";

        // When user input = false. (!false) = true 
        if (!(cin >> guessNumber)) {
            cout << "Please enter a valid number." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        numberOfGuess--;

        if(guessNumber == randomNumber) {
            playerScore++;
            randomNumber = generateRandom();
            printCorrect();
        } 
        else {
            printIncorrect();
            
        }
        cout << "Guesses remaining: " << numberOfGuess << endl 
             << " Your Score: " << playerScore << endl << endl;
    }

    printGameOver(playerScore);

    return 0;
}