/*
 * ╔══════════════════════════════════════════════════════════╗
 * ║          MINI GAME PROJECT — TIC TAC TOE  (C++)          ║
 * ║   Loops · Arrays · Conditional Logic · Replay Option     ║
 * ╚══════════════════════════════════════════════════════════╝
 */

#include <iostream>
#include <array>
#include <limits>

using namespace std;

// ─── Constants ────────────────────────────────────────────
const int SIZE = 3;

// ─── Board ────────────────────────────────────────────────
class TicTacToe {
private:
    array<array<char, SIZE>, SIZE> board;
    char currentPlayer;
    int  totalMoves;

    // ── Initialize board with position numbers ────────────
    void initBoard() {
        char cell = '1';
        for (auto& row : board)
            for (auto& c : row)
                c = cell++;
        currentPlayer = 'X';
        totalMoves    = 0;
    }

    // ── Display board dynamically after each move ─────────
    void displayBoard() const {
        cout << "\n";
        cout << "     1   2   3\n";
        cout << "   ┌───┬───┬───┐\n";

        for (int r = 0; r < SIZE; r++) {
            cout << " " << (r + 1) << " │";
            for (int c = 0; c < SIZE; c++) {
                char cell = board[r][c];
                // Color-code X and O visually
                if (cell == 'X')
                    cout << " X │";
                else if (cell == 'O')
                    cout << " O │";
                else
                    cout << " \033[90m" << cell << "\033[0m │";
            }
            cout << "\n";
            if (r < SIZE - 1)
                cout << "   ├───┼───┼───┤\n";
        }
        cout << "   └───┴───┴───┘\n";
    }

    // ── Check all win conditions using loops ──────────────
    bool checkWin() const {
        // Check rows and columns
        for (int i = 0; i < SIZE; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;

        return false;
    }

    bool checkDraw() const {
        return totalMoves == SIZE * SIZE;
    }

    // ── Get valid move from player ────────────────────────
    bool applyMove(int pos) {
        if (pos < 1 || pos > 9) return false;

        int r = (pos - 1) / SIZE;
        int c = (pos - 1) % SIZE;

        // Cell already taken
        if (board[r][c] == 'X' || board[r][c] == 'O') return false;

        board[r][c] = currentPlayer;
        totalMoves++;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

public:
    // ── Main game loop ────────────────────────────────────
    void play() {
        initBoard();

        cout << "\n  ══════════════════════════════\n";
        cout << "    TIC TAC TOE  |  X vs O\n";
        cout << "  ══════════════════════════════\n";
        cout << "  Enter the cell number (1-9) to place your mark.\n";

        while (true) {
            displayBoard();

            cout << "\n  Player " << currentPlayer << "'s turn → Enter position: ";
            int pos;

            // Input validation loop
            while (!(cin >> pos)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "  ✘ Invalid input. Enter a number (1-9): ";
            }

            if (!applyMove(pos)) {
                cout << "  ✘ Cell already taken or invalid. Try again.\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "\n  ╔══════════════════════════════╗\n";
                cout << "  ║  🎉 Player " << currentPlayer
                     << " WINS! Congrats!   ║\n";
                cout << "  ╚══════════════════════════════╝\n";
                return;
            }

            if (checkDraw()) {
                displayBoard();
                cout << "\n  ╔══════════════════════════════╗\n";
                cout << "  ║        It's a DRAW! 🤝        ║\n";
                cout << "  ╚══════════════════════════════╝\n";
                return;
            }

            switchPlayer();
        }
    }
};

// ─── Scoreboard ───────────────────────────────────────────
struct Score {
    int xWins = 0, oWins = 0, draws = 0;

    void update(char winner) {
        if (winner == 'X') xWins++;
        else if (winner == 'O') oWins++;
        else draws++;
    }

    void display() const {
        cout << "\n  ── Scoreboard ──────────────────\n";
        cout << "  Player X Wins : " << xWins << "\n";
        cout << "  Player O Wins : " << oWins << "\n";
        cout << "  Draws         : " << draws  << "\n";
        cout << "  ────────────────────────────────\n";
    }
};

// ─── Main ─────────────────────────────────────────────────
int main() {
    TicTacToe game;
    char replay;

    cout << "\n╔══════════════════════════════════╗\n";
    cout << "║    MINI GAME — TIC TAC TOE (C++) ║\n";
    cout << "╚══════════════════════════════════╝\n";

    // Replay loop
    do {
        game.play();

        cout << "\n  Play again? (y/n): ";
        cin  >> replay;

    } while (replay == 'y' || replay == 'Y');

    cout << "\n  Thanks for playing! Goodbye.\n\n";
    return 0;
}
