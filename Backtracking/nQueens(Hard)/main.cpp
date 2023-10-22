#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/n-queens/

//* SOLUTION
void backtrack(int currRow, int n, vector<vector<char>>& board,
               vector<vector<string>>& res, unordered_set<int>& colSet,
               unordered_set<int>& posDiagSet, unordered_set<int>& negDiagSet) {
    if (currRow == n) {
        vector<string> arrangement;
        for (auto i : board) {
            string row = "";
            for (auto ch : i) row += ch;
            arrangement.push_back(row);
        }
        res.push_back(arrangement);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (colSet.find(col) != colSet.end() ||
            posDiagSet.find(currRow + col) != posDiagSet.end() ||
            negDiagSet.find(currRow - col) != negDiagSet.end())
            continue;

        colSet.insert(col);
        posDiagSet.insert(currRow + col);
        negDiagSet.insert(currRow - col);

        board[currRow][col] = 'Q';

        backtrack(currRow + 1, n, board, res, colSet, posDiagSet, negDiagSet);

        colSet.erase(col);
        posDiagSet.erase(currRow + col);
        negDiagSet.erase(currRow - col);

        board[currRow][col] = '.';
    }
}
vector<vector<string>> solveNQueens(int n) {
    unordered_set<int> colSet, posDiagSet, negDiagSet;
    vector<vector<string>> res;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    backtrack(0, n, board, res, colSet, posDiagSet, negDiagSet);
    return res;
}

int main() {
    int n = 4;
    cout << "Number of Queens = " << n << "\n";

    vector<vector<string>> res = solveNQueens(n);
    cout << "Arrangements = [";
    for (int i = 0; i < res.size(); i++) {
        cout << "\n[\n";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "\n";
        }
        cout << "]";
        if (i != res.size() - 1) cout << ", ";
    }
    cout << "]\n";
    return 0;
}