#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/number-of-islands

//* SOLUTION
void dfs(int row, int col, vector<vector<char>>& grid,
         set<pair<int, int>>& visited, int totalRows, int totalCols) {

    stack<pair<int, int>> st;
    st.push({row, col});

    visited.insert({row, col});

    vector<pair<int, int>> directions = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    while (!st.empty()) {
        pair<int, int> dim = st.top();
        st.pop();
        int r = dim.first, c = dim.second;

        for (auto dir : directions) {
            int nextR = r + dir.first, nextC = c + dir.second;

            if ((nextR >= 0 && nextR < totalRows) &&
                (nextC >= 0 && nextC < totalCols) &&
                (grid[nextR][nextC] == '1') &&
                (visited.find({nextR, nextC}) == visited.end())) {
                st.push({nextR, nextC});
                visited.insert({nextR, nextC});
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    if (!rows) return 0;
    int cols = grid[0].size();
    int ans = 0;

    set<pair<int, int>> visited;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if ((grid[r][c] == '1') &&
                (visited.find({r, c}) == visited.end())) {
                dfs(r, c, grid, visited, rows, cols);
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
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

    cout << "Number of Islands = " << numIslands(grid) << "\n";

    return 0;
}