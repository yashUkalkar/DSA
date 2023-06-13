#include <iostream>
#include <map>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/group-anagrams/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    map<vector<int>, vector<string>> anagram_map;
    for (auto i : strs) {
        // Find letter occurence mapping
        vector<int> letter_map(26, 0);
        for (auto j : i) {
            int letter_index = int(j) - int('a');
            letter_map[letter_index]++;
        }

        if (anagram_map.find(letter_map) == anagram_map.end()) {
            // First occurrence
            vector<string> v = {i};
            anagram_map[letter_map] = v;
        } else {
            anagram_map[letter_map].push_back(i);
        }
    }

    for (auto i : anagram_map) {
        result.push_back(i.second);
    }

    return result;
}

int main() {
    vector<string> s{"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans = groupAnagrams(s);
    cout << "[ ";
    for (auto i : ans) {
        cout << "[";
        for (auto j : i) {
            cout << j << ",";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}