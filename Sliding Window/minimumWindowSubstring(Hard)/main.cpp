#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/minimum-window-substring/

string minWindow(string s, string t) {
    int res[] = {-1, -1};
    int resLength = INT_MAX;

    if (t == "") return "";

    unordered_map<char, int> freqMapT, freqMapWindow;

    for (auto i : t) freqMapT[i]++;

    int currMatches = 0, requiredMatches = freqMapT.size();

    int l = 0;
    for (int r = 0; r < s.length(); r++) {
        freqMapWindow[s[r]]++;

        if ((freqMapT.find(s[r]) != freqMapT.end()) &&
            (freqMapWindow[s[r]] == freqMapT[s[r]])) {
            currMatches++;
        }

        while (currMatches == requiredMatches) {
            // If current window is an answer and has length less than our
            // previous substring
            if (r - l + 1 < resLength) {
                res[0] = l;
                res[1] = r;
                resLength = r - l + 1;
            }

            // Pop from left of window to minimize string
            freqMapWindow[s[l]]--;
            if ((freqMapWindow.find(s[l]) != freqMapWindow.end()) &&
                (freqMapWindow[s[l]] < freqMapT[s[l]])) {
                currMatches--;
            }

            l++;
        }
    }

    if (resLength != INT_MAX)
        return s.substr(res[0], res[1] - res[0] + 1);
    else
        return "";
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";

    cout << minWindow(s, t);

    return 0;
}