#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// * Link - https://leetcode.com/problems/contains-duplicate/

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> freq_map;

    for (auto i : nums) {
        if (freq_map.find(i) == freq_map.end())
            freq_map[i] = 1;
        else
            return true;
    }

    return false;
}

int main() {
    vector<int> v{1, 2, 3, 4, 1};
    cout << containsDuplicate(v);
    return 0;
}