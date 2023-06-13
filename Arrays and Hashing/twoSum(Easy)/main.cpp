#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/two-sum/

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> comp_map;

    for (int i = 0; i < nums.size(); i++) {
        int i_complement = target - i;

        auto val = comp_map.find(i_complement);
        if (val == comp_map.end()) {
            // No previous value found
            comp_map[nums[i]] = i;
        } else {
            // Pair found
            ans.push_back(val->second);
            ans.push_back(i);
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> s{2, 7, 11, 15};
    int t = 9;

    vector<int> ans = twoSum(s, t);
    cout << "[ ";
    for (auto i : ans) cout << i << " ";
    cout << "]";

    return 0;
}