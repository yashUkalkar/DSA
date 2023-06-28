#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/minimum-path-sum/description/

//* SOLUTION
int minPathSum(vector<vector<int>>& grid) {
    // Bottom up approach
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, INT_MAX));
    dp[rows - 1][cols] = 0;

    for (int r = rows - 1; r >= 0; r--) {
        for (int c = cols - 1; c >= 0; c--) {
            dp[r][c] = grid[r][c] + min(dp[r + 1][c], dp[r][c + 1]);
        }
    }

    return dp[0][0];

    // TODO: optimize memory complexity to O(n)
    /*
        Above solution uses O(n^2) space since we store DP array
        of size same as the dimensions of the "grid".
        * We only need to store the row below and the column next to
        * the element being processed at a given time.
        * This reduces the space complexity to O(n).
    */
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    cout << minPathSum(grid);

    return 0;
}