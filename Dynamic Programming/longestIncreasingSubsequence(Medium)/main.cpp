#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/longest-increasing-subsequence/

//* SOLUTION
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] < nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }

    int maxDP = dp[0];
    for (auto i : dp) {
        if (i > maxDP) maxDP = i;
    }
    return maxDP;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Input = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Longest increasing subsequence length = " << lengthOfLIS(nums)
         << "\n";

    return 0;
}