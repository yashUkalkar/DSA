#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/combination-sum/

//* SOLUTION
void dfs(vector<int>& candidates, vector<vector<int>>& res, int index,
         vector<int>& currentCombination, int currentTotal, int target) {
    if (currentTotal == target) {
        res.push_back(vector<int>(currentCombination));
        return;
    }

    if (index >= candidates.size() || currentTotal > target) return;

    //* Include current value for combination
    currentCombination.push_back(candidates[index]);
    dfs(candidates, res, index, currentCombination,
        currentTotal + candidates[index], target);

    //* Don't include the current element for combination
    currentCombination.pop_back();

    dfs(candidates, res, ++index, currentCombination, currentTotal, target);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> currentCombination;

    dfs(candidates, res, 0, currentCombination, 0, target);

    return res;
}

int main() {
    vector<int> candidates = {2, 3, 5};
    int target = 8;

    vector<vector<int>> res = combinationSum(candidates, target);

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