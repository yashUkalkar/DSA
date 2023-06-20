#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/search-a-2d-matrix/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row_t = 0, col_l = 0, row_b = matrix.size() - 1,
        col_r = matrix[0].size() - 1;

    // Find required row where number might be present
    while (row_t < row_b) {
        int row_mid = (row_t + row_b) / 2;

        if (target > matrix[row_mid][col_r])
            row_t = ++row_mid;
        else if (target < matrix[row_mid][col_l])
            row_b = --row_mid;
        else
            break;
    }

    if (!(row_t <= row_b)) return false;

    // Perform binary search for row found
    int row = (row_t + row_b) / 2;

    while (col_l <= col_r) {
        int col_mid = (col_l + col_r) / 2;

        if (matrix[row][col_mid] == target)
            return true;
        else if (matrix[row][col_mid] < target)
            col_l = ++col_mid;
        else
            col_r = --col_mid;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 23;

    if (searchMatrix(mat, target))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}