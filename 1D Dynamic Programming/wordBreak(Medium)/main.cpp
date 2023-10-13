#include <iostream>
#include <string>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/word-break/

//* SOLUTION
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();

    vector<bool> dp(n + 1, false);
    dp[n] = true;

    for (int i = n - 1; i >= 0; i--) {
        for (auto word : wordDict) {
            int wLen = word.length();
            if ((i + wLen <= n) && (s.substr(i, wLen) == word))
                dp[i] = dp[i + wLen];
            if (dp[i]) break;
        }
    }

    return dp[0];
}

int main() {
    string s = "leetcodeleet";
    vector<string> wordDict = {"leet", "code"};

    cout << "Word = '" << s << "'\n";
    cout << "Words Dcitionary = [";
    for (int i = 0; i < wordDict.size(); i++) {
        cout << "'" << wordDict[i] << "'";
        if (i != wordDict.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << (wordBreak(s, wordDict) ? "True" : "False");

    return 0;
}