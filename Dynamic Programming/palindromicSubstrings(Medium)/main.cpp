#include <iostream>
using namespace std;

//* Link - https://leetcode.com/problems/palindromic-substrings/

//* SOLUTION
int countSubstrings(string s) {
    int n = s.length();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // Checking odd length palindrome
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            ans += 1;
            l -= 1;
            r += 1;
        }

        // Checking even length palindromes
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            ans += 1;
            l -= 1;
            r += 1;
        }
    }

    return ans;
}

int main() {
    string s = "aaabb";
    cout << "Input string = '" << s << "'\n";
    cout << "Palindrome count = " << countSubstrings(s) << "\n";
    return 0;
}