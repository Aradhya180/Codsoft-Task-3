#include <iostream>
#include <vector>

// Function to initialize the game board
std::vector<std::vector<char>> InitializeBoard() {
    return {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
}

// Function to display the game board
void DisplayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------\n";
    }
    std::cout << std::endl;
}

// Function to check if the current player has won
bool CheckForWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Check columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Check diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Check reverse diagonal
    return false;
}

// Function to check if the game is a draw
bool CheckForDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false; // If there is an empty space, the game is not a draw
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board = InitializeBoard();
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    std::cout << "TIC-TAC-TOE GAME\n";
    
    while (!gameWon && !gameDraw) {
        DisplayBoard(board);
        std::cout << "Player " << currentPlayer << "'s turn. Enter your move (row and column): ";
        int row, col;
        std::cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again.\n";
        } else {
            board[row][col] = currentPlayer;
            gameWon = CheckForWin(board, currentPlayer);
            gameDraw = CheckForDraw(board);
            if (gameWon) {
                DisplayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
            } else if (gameDraw) {
                DisplayBoard(board);
                std::cout << "It's a draw!\n";
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
            }
        }
    }

    return 0;
}
