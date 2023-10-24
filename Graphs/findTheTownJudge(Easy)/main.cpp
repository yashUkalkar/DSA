#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/find-the-town-judge

//* SOLUTION
int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> countTrust(n + 1, 0);

    for (auto trustRel : trust) {
        countTrust[trustRel[0]]--;
        countTrust[trustRel[1]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (countTrust[i] == n - 1) return i;
    }

    return -1;
}

int main() {
    int n = 3;
    cout << "Population = " << n << "\n";

    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    cout << "Trust = [";
    for (int i = 0; i < trust.size(); i++) {
        cout << "[";
        for (int j = 0; j < trust[i].size(); j++) {
            cout << trust[i][j];
            if (j != trust[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i != trust.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Town judge = " << findJudge(n, trust);

    return 0;
}