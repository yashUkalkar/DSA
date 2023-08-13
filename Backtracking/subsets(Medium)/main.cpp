#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/subsets/

//* SOLUTION
void dfs(vector<int>& nums, vector<vector<int>>& res,
         vector<int>& currentSubset, int index) {

    if (index >= nums.size()) {
        res.push_back(vector<int>(currentSubset));
        return;
    }

    // Include the current index element
    currentSubset.push_back(nums[index]);
    dfs(nums, res, currentSubset, index + 1);

    // Don't include the current index element
    currentSubset.pop_back();
    dfs(nums, res, currentSubset, index + 1);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> currentSubset;

    dfs(nums, res, currentSubset, 0);

    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << "Input = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";

    vector<vector<int>> res = subsets(nums);

    cout << "Power set = [";
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