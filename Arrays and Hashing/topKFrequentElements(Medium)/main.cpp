#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/top-k-frequent-elements/

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;

    unordered_map<int, int> freq_map;
    for (auto i : nums) {
        if (freq_map.find(i) == freq_map.end()) {
            freq_map[i] = 1;
        } else {
            freq_map[i]++;
        }
    }

    int arr_len = nums.size();
    vector<vector<int>> count_arr(arr_len + 1);

    for (auto i : freq_map) {
        count_arr[i.second].push_back(i.first);
    }

    while (k > 0) {
        if (count_arr[arr_len].size()) {
            for (auto i : count_arr[arr_len]) {
                result.push_back(i);
                k--;
            }
        }
        arr_len--;
    }

    return result;
}

int main() {
    vector<int> v{1, 1, 1, 2, 2, 3, 3, 3};
    int k = 2;

    vector<int> result = topKFrequent(v, k);
    cout << "[ ";
    for (auto i : result) cout << i << " ";
    cout << "]";
    return 0;
}