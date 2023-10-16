#include <iostream>
#include <string>
using namespace std;

//* Link - https://leetcode.com/problems/longest-palindromic-substring/

//* SOLUTION
string longestPalindrome(string s) {
    string ans = "";
    int currLength = 0;

    int n = s.length();
    for (int i = 0; i < n; i++) {
        // Checking odd length palindromes
        int l = i, r = i;

        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > currLength) {
                ans = s.substr(l, r - l + 1);
                currLength = r - l + 1;
            }
            l -= 1;
            r += 1;
        }

        // Checking even length palindromes
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > currLength) {
                ans = s.substr(l, r - l + 1);
                currLength = r - l + 1;
            }
            l -= 1;
            r += 1;
        }
    }

    return ans;
}

int main() {
    string s = "babadaba";
    cout << "Input string = '" << s << "'\n";
    cout << "Longest palindromic substring = '" << longestPalindrome(s)
         << "'\n";
    return 0;
}