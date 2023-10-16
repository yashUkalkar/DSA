#include <iostream>
#include <unordered_map>
using namespace std;

//* Link - https://leetcode.com/problems/decode-ways/

//* SOLUTION
int dfs(string s, int index, unordered_map<int, int>& dp) {
    if (dp.find(index) != dp.end()) return dp[index];

    if (s[index] == '0') return 0;

    int res = dfs(s, index + 1, dp);
    if ((index + 1 < s.length()) && (s[index] == '1') ||
        (s[index] == '2' &&
         (s[index + 1] == '0' || s[index + 1] == '1' || s[index + 1] == '2' ||
          s[index + 1] == '3' || s[index + 1] == '4' || s[index + 1] == '5' ||
          s[index + 1] == '6')))
        res += dfs(s, index + 2, dp);

    dp[index] = res;

    return res;
}
int numDecodings(string s) {
    unordered_map<int, int> dp;
    dp[s.length()] = 1;

    return dfs(s, 0, dp);
}

int main() {
    string s = "11106";
    cout << "Code = '" << s << "'\n";
    cout << "Ways to decode = " << numDecodings(s) << "\n";
    return 0;
}