#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/longest-consecutive-sequence/

int longestConsecutiveSequence(vector<int>& nums) {
    int longest_len = 0;

    unordered_set<int> numSet(nums.begin(), nums.end());
    for (auto num : numSet) {
        if (numSet.find(num - 1) == numSet.end()) {
            int current_num = num;
            int current_len = 1;

            while (numSet.find(current_num + 1) != numSet.end()) {
                current_num++;
                current_len++;
            }

            longest_len = max(longest_len, current_len);
        }
    }

    return longest_len;
}

int main() {
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    int ans = longestConsecutiveSequence(nums);
    cout << ans;

    return 0;
}