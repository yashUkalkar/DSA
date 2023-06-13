#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

//* Link - https://leetcode.com/problems/valid-palindrome/

bool isPalindrome(string s) {

    // Convert string to required format
    string converted_str = "";
    for (auto i : s) {
        if (isalnum(i)) converted_str.push_back(tolower(i));
    }

    // Check if palindrome
    int l = 0, r = converted_str.length() - 1;
    while (l <= r) {
        if (converted_str[l] != converted_str[r])
            return false;
        else {
            l++;
            r--;
        }
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";

    if (isPalindrome(s))
        cout << "True";
    else
        cout << "False";

    return 0;
}