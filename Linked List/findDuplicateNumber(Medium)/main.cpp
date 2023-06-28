#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/find-the-duplicate-number/

//* SOLUTION
int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    int slow2 = 0;
    do {
        slow = nums[slow];
        slow2 = nums[slow2];
    } while (slow != slow2);

    return slow;
}

//* Driver code
int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << findDuplicate(nums);
    return 0;
}