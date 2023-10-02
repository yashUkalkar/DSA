#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/permutations/

//* SOLUTION
void dfs(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[i], nums[start]);
        dfs(nums, start + 1, result);
        swap(nums[i], nums[start]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    dfs(nums, 0, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> res = permute(nums);

    cout << "Input = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Permutations = [";
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