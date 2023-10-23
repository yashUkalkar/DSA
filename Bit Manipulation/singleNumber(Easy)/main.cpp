#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/single-number/

//* SOLUTION
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto i : nums) res ^= i;

    return res;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 7};
    cout << "Input = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Answer = " << singleNumber(nums);

    return 0;
}