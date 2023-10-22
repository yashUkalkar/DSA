#include <iostream>
#include <set>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/max-area-of-island/

//* SOLUTION
int dfs(int r, int c, vector<vector<int>>& grid, int totalRows, int totalCols,
        set<pair<int, int>>& visited) {
    if (r < 0 || r >= totalRows || c < 0 || c >= totalCols || grid[r][c] == 0 ||
        visited.find({r, c}) != visited.end())
        return 0;

    visited.insert({r, c});

    int area = 1;  // For current island
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (auto dir : directions) {
        int nextR = r + dir.first, nextC = c + dir.second;
        area += dfs(nextR, nextC, grid, totalRows, totalCols, visited);
    }

    return area;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    set<pair<int, int>> visited;

    int res = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            res = max(res, dfs(r, c, grid, rows, cols, visited));
        }
    }

    return res;
}

int main() {
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << "Grid = [\n";
    for (int i = 0; i < grid.size(); i++) {
        cout << "[";
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j];
            if (j != grid[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i != grid.size() - 1) cout << ", \n";
    }
    cout << "\n]\n";

    cout << "Max area = " << maxAreaOfIsland(grid) << "\n";

    return 0;
}