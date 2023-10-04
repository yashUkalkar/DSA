#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/house-robber/

//* SOLUTION
int rob(vector<int>& nums) {
    int amountPrevToPrevHouse = 0, amountPrevHouse = 0;

    // Array order = [..., amountPrevToPrevHouse, amountPrevHouse,
    // currentHouseAmount, ...]
    for (auto currentHouseAmount : nums) {
        int currentMaxAmount =
            max(amountPrevToPrevHouse + currentHouseAmount, amountPrevHouse);
        amountPrevToPrevHouse = amountPrevHouse;
        amountPrevHouse = currentMaxAmount;
    }

    return amountPrevHouse;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << "Money = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Max amount = " << rob(nums) << "\n";
    return 0;
}