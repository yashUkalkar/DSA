#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/

//* SOLUTION
void createCharMap(unordered_map<char, string>& charMap) {
    charMap['2'] = "abc";
    charMap['3'] = "def";
    charMap['4'] = "ghi";
    charMap['5'] = "jkl";
    charMap['6'] = "mno";
    charMap['7'] = "pqrs";
    charMap['8'] = "tuv";
    charMap['9'] = "wxyz";
}
void backtrack(string& digits, int index, string currString,
               vector<string>& res, unordered_map<char, string>& charMap) {
    if (currString.length() == digits.length()) {
        res.push_back(currString);
        return;
    }

    for (auto c : charMap[digits[index]])
        backtrack(digits, index + 1, currString + c, res, charMap);
}
vector<string> letterCombinations(string digits) {
    unordered_map<char, string> charMap;
    createCharMap(charMap);

    vector<string> res;
    if (digits.length() > 0) backtrack(digits, 0, "", res, charMap);
    return res;
}

int main() {
    string digits = "23";
    cout << "Digits = " << digits << "\n";

    vector<string> res = letterCombinations(digits);
    cout << "Combinations = [";
    for (int i = 0; i < res.size(); i++) {
        cout << "'" << res[i] << "'";
        if (i != res.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}