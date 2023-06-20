#include <iostream>
#include <unordered_set>
using namespace std;

//* Link -
//* https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

int lengthOfLongestSubstring(string s) {
    int res = 0;

    unordered_set<int> set;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
        while (set.find(s[r]) != set.end()) {
            set.erase(s[l]);
            l++;
        }

        set.insert(s[r]);

        res = max(res, r - l + 1);
    }

    return res;
}

int main() {
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s);

    return 0;
}