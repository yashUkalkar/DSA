#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/house-robber-ii/

//* SOLUTION
int rob(vector<int>& nums) {
    int currentMaxAmount = nums[0];
    if (nums.size() == 1) return currentMaxAmount;

    // Robbing house 1, i.e. excluding last house
    int amountPrevToPrevHouseWithFirst = 0, amountPrevHouseWithFirst = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        currentMaxAmount = max(amountPrevToPrevHouseWithFirst + nums[i],
                               amountPrevHouseWithFirst);
        amountPrevToPrevHouseWithFirst = amountPrevHouseWithFirst;
        amountPrevHouseWithFirst = currentMaxAmount;
    }

    currentMaxAmount = nums[0];

    // Robbing house 2 first, i.e. excluding first house
    int amountPrevToPrevHouseWithLast = 0, amountPrevHouseWithLast = 0;
    for (int i = 1; i < nums.size(); i++) {
        currentMaxAmount = max(amountPrevToPrevHouseWithLast + nums[i],
                               amountPrevHouseWithLast);
        amountPrevToPrevHouseWithLast = amountPrevHouseWithLast;
        amountPrevHouseWithLast = currentMaxAmount;
    }

    return max(amountPrevHouseWithFirst, amountPrevHouseWithLast);
}

int main() {
    vector<int> nums = {1};
    cout << "Money = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Max amount = " << rob(nums) << "\n";
    return 0;
}