#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/search-in-rotated-sorted-array/

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) return mid;

        if (nums[mid] >= nums[l]) {
            if (target > nums[mid] || target < nums[l])
                l = ++mid;
            else
                r = --mid;
        } else {
            if (target < nums[mid] || target > nums[r])
                r = --mid;
            else
                l = ++mid;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << search(nums, target);

    return 0;
}