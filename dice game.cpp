#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to roll the dice
int rollDice()
{
    return rand() % 6 + 1; // Random number between 1 and 6
}

// Function to play the game
void playGame(int numPlayers)
{
    int scores[numPlayers] = {0}; // Initialize scores to zero
    int maxScore = 0; // Initialize maximum score to zero

    // Loop through each player
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "Player " << i + 1 << ", press enter to roll the dice...";
        cin.ignore(); // Wait for the player to press enter
        int score = rollDice(); // Roll the dice and get the score
        cout << "You rolled a " << score << "!" << endl;
        scores[i] = score; // Update the player's score

        if (score > maxScore) // Update the maximum score
        {
            maxScore = score;
        }
    }

    // Loop through each player and print their score
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "Player " << i + 1 << " scored " << scores[i] << endl;
    }

    // Print the winner(s)
    cout << "The winner(s) is/are: ";
    for (int i = 0; i < numPlayers; i++)
    {
        if (scores[i] == maxScore)
        {
            cout << "Player " << i + 1 << " ";
        }
    }
    cout << "with a score of " << maxScore << "!" << endl;
}

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time

    int numPlayers;
    cout << "How many players? ";
    cin >> numPlayers;

    playGame(numPlayers);

    return 0;
}
