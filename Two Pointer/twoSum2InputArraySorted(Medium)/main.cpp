#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    vector<int> res;

    while (l < r) {
        int num_sum = numbers[l] + numbers[r];

        if (num_sum == target) {
            res.push_back(++l);
            res.push_back(++r);
            return res;
        } else if (num_sum < target)
            l++;
        else
            r--;
    }

    return res;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 22;

    vector<int> indices = twoSum(nums, target);
    cout << "Indices = [ ";
    for (auto i : indices) cout << i << " ";
    cout << "]\n";

    return 0;
}