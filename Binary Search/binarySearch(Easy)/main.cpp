#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/binary-search/

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            l = ++mid;
        else
            r = --mid;
    }

    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << search(nums, target);

    return 0;
}