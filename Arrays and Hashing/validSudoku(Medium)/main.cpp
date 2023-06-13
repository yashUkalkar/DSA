#include <iostream>
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/valid-sudoku/

bool isValidSudoku(vector<vector<char>>& board) {

    map<int, unordered_set<char>> rows;
    map<int, unordered_set<char>> cols;
    map<pair<int, int>, unordered_set<char>> squares;  // For each 3X3 subcube

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            char i = board[r][c];
            pair<int, int> square_i = make_pair(r / 3, c / 3);

            if (i == '.')
                continue;
            else if (rows[r].find(i) != rows[r].end() ||
                     cols[c].find(i) != cols[c].end() ||
                     squares[square_i].find(i) != squares[square_i].end())
                return false;
            else {
                rows[r].insert(i);
                cols[c].insert(i);
                squares[square_i].insert(i);
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    bool ans = isValidSudoku(board);
    if (ans)
        cout << "Valid board";
    else
        cout << "Invalid board";

    return 0;
}