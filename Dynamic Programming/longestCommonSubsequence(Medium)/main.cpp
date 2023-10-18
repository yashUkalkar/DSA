#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/longest-common-subsequence/

//* SOLUTION
int longestCommonSubsequence(string text1, string text2) {
    int lenText1 = text1.length(), lenText2 = text2.length();
    vector<vector<int>> dp(lenText1 + 1, vector<int>(lenText2 + 1, 0));

    for (int r = lenText1 - 1; r >= 0; r--) {
        for (int c = lenText2 - 1; c >= 0; c--) {
            if (text1[r] == text2[c]) {
                dp[r][c] = 1 + dp[r + 1][c + 1];
            } else {
                dp[r][c] = max(dp[r + 1][c], dp[r][c + 1]);
            }
        }
    }

    return dp[0][0];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";

    cout << "String 1 = '" << text1 << "'\n";
    cout << "String 2 = '" << text2 << "'\n";

    cout << "Length of longest common subsequence = "
         << longestCommonSubsequence(text1, text2) << "\n";

    return 0;
}