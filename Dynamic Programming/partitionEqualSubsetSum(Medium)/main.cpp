#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/partition-equal-subset-sum/

//* SOLUTION
bool canPartition(vector<int>& nums) {
    int arrSum = 0;
    for (auto i : nums) arrSum += i;

    if (arrSum % 2 != 0) return false;

    unordered_set<int> dp;
    dp.insert(0);

    int halfSum = arrSum / 2, n = nums.size();
    for (int i = n - 1; i >= 0; i--) {
        if (dp.find(halfSum) != dp.end()) return true;

        unordered_set<int> tempDP;
        for (auto val : dp) {
            tempDP.insert(val + nums[i]);
            tempDP.insert(val);
        }
        dp = tempDP;
    }

    return dp.find(halfSum) != dp.end();
}

int main() {
    vector<int> nums = {1, 5, 11, 7};
    cout << "Input = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << (canPartition(nums) ? "True" : "False") << "\n";

    return 0;
}