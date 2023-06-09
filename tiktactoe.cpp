#include <iostream>
#include <vector>
using namespace std;

// Function to print the tic-tac-toe board
void print_board(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to check if a player has won
bool check_win(const vector<char>& board, char player) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i+1] == player && board[i+2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i+3] == player && board[i+6] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }
    // No win found
    return false;
}

int main() {
    vector<char> board(9, ' '); // Initialize the board to all empty spaces
    bool game_over = false;
    char player = 'X';

    while (!game_over) {
        // Print the board and prompt the player for their move
        print_board(board);
        cout << "Player " << player << ", enter a move (0-8): ";
        int move;
        cin >> move;

        // Check if the move is valid
        if (board[move] != ' ') {
            cout << "Invalid move. That space is already taken.\n";
            continue;
        }

        // Update the board with the player's move
        board[move] = player;

        // Check if the player has won
        if (check_win(board, player)) {
            print_board(board);
            cout << "Player " << player << " wins!\n";
            game_over = true;
        }

        // Check if the board is full and the game is a tie
        bool board_full = true;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board_full = false;
                break;
            }
        }
        if (board_full) {
            print_board(board);
            cout << "Tie game.\n";
            game_over = true;
        }

        // Switch to the other player
        player = player == 'X' ? 'O' : 'X';
    }

    return 0;
}
