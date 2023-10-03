#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/word-search/

//* SOLUTION
bool backtrack(vector<vector<char>>& board, string word, int totalRows,
               int totalCols, int currentRow, int currentCol,
               int currentWordIndex, set<pair<int, int>>& currentPath) {
    if (currentWordIndex == word.length()) return true;  // Found the word

    if (currentRow < 0 || currentCol < 0 || currentRow >= totalRows ||
        currentCol >= totalCols ||
        word[currentWordIndex] != board[currentRow][currentCol] ||
        currentPath.find({currentRow, currentCol}) != currentPath.end())
        return false;

    currentPath.insert(make_pair(currentRow, currentCol));

    bool res = (backtrack(board, word, totalRows, totalCols, currentRow + 1,
                          currentCol, currentWordIndex + 1, currentPath) ||
                backtrack(board, word, totalRows, totalCols, currentRow - 1,
                          currentCol, currentWordIndex + 1, currentPath) ||
                backtrack(board, word, totalRows, totalCols, currentRow,
                          currentCol + 1, currentWordIndex + 1, currentPath) ||
                backtrack(board, word, totalRows, totalCols, currentRow,
                          currentCol - 1, currentWordIndex + 1, currentPath));

    currentPath.erase({currentRow, currentCol});
    return res;
}
bool exist(vector<vector<char>>& board, string word) {
    int totalRows = board.size(), totalCols = board[0].size();

    set<pair<int, int>> currentPath;

    for (int row = 0; row < totalRows; row++) {
        for (int col = 0; col < totalCols; col++) {
            if (backtrack(board, word, totalRows, totalCols, row, col, 0,
                          currentPath))
                return true;
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCFSADE";

    cout << "Board = [\n";
    for (int i = 0; i < board.size(); i++) {
        cout << "[";
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j];
            if (j != board[i].size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";

    cout << "Word = " << word << "\n";

    cout << (exist(board, word) ? "True" : "False");

    return 0;
}