#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/combination-sum-ii/

//* SOLUTION
void backtrack(vector<int>& candidates, vector<vector<int>>& res,
               int currentIndex, vector<int>& currentCombination,
               int currentTotal, int target) {
    if (currentTotal == target) {
        res.push_back(vector<int>(currentCombination));
        return;
    }

    if (currentIndex >= candidates.size() || currentTotal > target) return;

    // Include current value for combination
    currentCombination.push_back(candidates[currentIndex]);
    backtrack(candidates, res, currentIndex + 1, currentCombination,
              currentTotal + candidates[currentIndex], target);

    // Don't include current value for combination
    currentCombination.pop_back();
    while (currentIndex + 1 < candidates.size() &&
           candidates[currentIndex] == candidates[currentIndex + 1])
        currentIndex++;  // Skipping same values
    backtrack(candidates, res, currentIndex + 1, currentCombination,
              currentTotal, target);
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> currentCombination;

    sort(candidates.begin(), candidates.end());
    backtrack(candidates, res, 0, currentCombination, 0, target);

    return res;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> res = combinationSum2(candidates, target);

    cout << "Input = [";
    for (int i = 0; i < candidates.size(); i++) {
        cout << candidates[i];
        if (i != candidates.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Combinations = [";
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j != res[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != res.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}