#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

int findMin(vector<int>& nums) {
    int res = nums[0];

    int l = 0, r = nums.size() - 1;

    while (l < r) {
        if (nums[l] < nums[r]) {
            res = min(res, nums[l]);
            break;
        }

        int mid = (l + r) / 2;
        res = min(res, nums[mid]);

        if (nums[mid] >= nums[l])
            l = ++mid;
        else
            r = --mid;
    }

    return res;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << findMin(nums);

    return 0;
}