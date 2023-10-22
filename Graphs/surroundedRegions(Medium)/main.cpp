#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/surrounded-regions/

//* SOLUTION
void dfs(int r, int c, vector<vector<char>>& board, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') return;

    board[r][c] = 'U';
    dfs(r + 1, c, board, rows, cols);
    dfs(r - 1, c, board, rows, cols);
    dfs(r, c + 1, board, rows, cols);
    dfs(r, c - 1, board, rows, cols);
}
void solve(vector<vector<char>>& board) {
    int rows = board.size(), cols = board[0].size();

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (board[r][c] == 'O' &&
                (r == 0 || r == rows - 1 || c == 0 || c == cols - 1))
                dfs(r, c, board, rows, cols);
        }
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (board[r][c] == 'U')
                board[r][c] = 'O';
            else
                board[r][c] = 'X';
        }
    }
}

int main() {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    cout << "Board = [\n";
    for (int i = 0; i < board.size(); i++) {
        cout << "[";
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j];
            if (j != board[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i != board.size() - 1) cout << ", \n";
    }
    cout << "\n]\n";

    solve(board);

    cout << "Board after capture = [\n";
    for (int i = 0; i < board.size(); i++) {
        cout << "[";
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j];
            if (j != board[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i != board.size() - 1) cout << ", \n";
    }
    cout << "\n]\n";

    return 0;
}