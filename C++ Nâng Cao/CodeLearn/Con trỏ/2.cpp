#include <iostream>
#include <climits>
#include <vector>
using namespace std;

const int BOARD_SIZE = 15;
char board[BOARD_SIZE][BOARD_SIZE];

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout << "  ";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(int row, int col, char player) {
    int count = 0;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[row][i] == player) {
            count++;
            if (count == 5) return true;
        } else {
            count = 0;
        }
    }

    count = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][col] == player) {
            count++;
            if (count == 5) return true;
        } else {
            count = 0;
        }
    }

    count = 0;
    for (int i = -4; i <= 4; ++i) {
        int r = row + i;
        int c = col + i;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
            if (board[r][c] == player) {
                count++;
                if (count == 5) return true;
            } else {
                count = 0;
            }
        }
    }

    count = 0;
    for (int i = -4; i <= 4; ++i) {
        int r = row + i;
        int c = col - i;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
            if (board[r][c] == player) {
                count++;
                if (count == 5) return true;
            } else {
                count = 0;
            }
        }
    }

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool gameOver() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] != ' ' && checkWin(i, j, board[i][j])) {
                return true;
            }
        }
    }

    return isBoardFull();
}

char checkWinner() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] != ' ' && checkWin(i, j, board[i][j])) {
                return board[i][j];
            }
        }
    }

    return ' ';
}

void makeMove(int row, int col, char player) {
    board[row][col] = player;
}

void undoMove(int row, int col) {
    board[row][col] = ' ';
}

vector<pair<int, int>> generateMoves() {
    vector<pair<int, int>> moves;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ') {
                moves.push_back({i, j});
            }
        }
    }
    return moves;
}

int evaluate() {
    // Đánh giá tình hình bàn cờ, có thể điều chỉnh để phù hợp hơn
    return 0;
}

int minimax(char player, int depth, int alpha, int beta) {
    if (depth == 0 || gameOver()) {
        return evaluate();
    }

    vector<pair<int, int>> moves = generateMoves();

    if (player == 'X') {
        int maxEval = INT_MIN;
        for (const auto& move : moves) {
            makeMove(move.first, move.second, player);
            int eval = minimax('O', depth - 1, alpha, beta);
            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            undoMove(move.first, move.second);
            if (beta <= alpha) break;
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (const auto& move : moves) {
            makeMove(move.first, move.second, player);
            int eval = minimax('X', depth - 1, alpha, beta);
            minEval = min(minEval, eval);
            beta = min(beta, eval);
            undoMove(move.first, move.second);
            if (beta <= alpha) break;
        }
        return minEval;
    }
}

void makePlayerMove() {
    int row, col;
    cout << "Nhập nước đi của bạn (dòng cột): ";
    cin >> row >> col;

    while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        cout << "Nước đi không hợp lệ. Nhập lại: ";
        cin >> row >> col;
    }

    makeMove(row, col, 'X');
}

void makeComputerMove() {
    vector<pair<int, int>> moves = generateMoves();
    int bestMove = -1;
    int bestEval = INT_MIN;

    for (int i = 0; i < moves.size(); ++i) {
        makeMove(moves[i].first, moves[i].second, 'O');
        int eval = minimax('X', 3, INT_MIN, INT_MAX);
        undoMove(moves[i].first, moves[i].second);

        if (eval > bestEval) {
            bestEval = eval;
            bestMove = i;
        }
    }

    makeMove(moves[bestMove].first, moves[bestMove].second, 'O');
}

int main() {
    initBoard();

    while (!gameOver()) {
        displayBoard();
        makePlayerMove();
        if (gameOver()) break;
        makeComputerMove();
    }

    displayBoard();
    char winner = checkWinner();
    if (winner != ' ') {
        cout << "Người chơi " << winner << " thắng!" << endl;
    } else {
        cout << "Trò chơi hòa!" << endl;
    }

    return 0;
}
