#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/subsets-ii/

//* SOLUTION
void backtrack(vector<int>& nums, vector<vector<int>>& res,
               vector<int>& currentSubset, int currentIndex) {
    if (currentIndex == nums.size()) {
        res.push_back(vector<int>(currentSubset));
        return;
    }

    // Include nums[currentIndex]
    currentSubset.push_back(nums[currentIndex]);
    backtrack(nums, res, currentSubset, currentIndex + 1);

    // Exclude nums[currentIndex]
    currentSubset.pop_back();
    while (currentIndex + 1 < nums.size() &&
           nums[currentIndex] == nums[currentIndex + 1])
        currentIndex++;  // Skipping same values
    backtrack(nums, res, currentSubset, currentIndex + 1);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> currentSubset;

    sort(nums.begin(), nums.end());
    backtrack(nums, res, currentSubset, 0);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 2};
    cout << "Input = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";

    vector<vector<int>> res = subsetsWithDup(nums);

    cout << "Subsets = [";
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