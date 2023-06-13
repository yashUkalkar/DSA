#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/3sum/

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        // Repeated first number(avoiding duplicates)
        if ((i > 0) && (nums[i] == nums[i - 1])) continue;

        // Finding corresponding twosum adding to 0
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int numSum = nums[i] + nums[l] + nums[r];
            if (numSum < 0)
                l++;
            else if (numSum > 0)
                r--;
            else {
                vector<int> sum_pair = {nums[i], nums[l], nums[r]};
                res.push_back(sum_pair);
                l++;
                // Skipping repeated numbers
                while ((nums[l] == nums[l - 1]) && (l < r)) l++;
            }
        }
    }

    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum(nums);
    cout << "Answer : [";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
            if (j != ans[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}