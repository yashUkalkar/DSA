#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/unique-paths/

//* SOLUTION
int uniquePaths(int m, int n) {
    vector<int> row(n, 1);

    for (int i = 0; i < m - 1; i++) {
        vector<int> newRow(n, 1);
        for (int j = n - 2; j >= 0; j--) {
            newRow[j] = newRow[j + 1] + row[j];
        }
        row = newRow;
    }

    return row[0];
}

int main() {
    int m = 3, n = 7;
    cout << "Number of rows = " << m << "\n";
    cout << "Number of columns = " << n << "\n";

    cout << "Number of unique paths = " << uniquePaths(m, n) << "\n";

    return 0;
}