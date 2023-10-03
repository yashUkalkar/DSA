#include <iostream>
#include <string>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/palindrome-partitioning/

//* SOLUTION
bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;

        start++;
        end--;
    }

    return true;
}
void backtrack(string s, vector<vector<string>>& res,
               vector<string>& currentPartition, int currentIndex) {
    if (currentIndex >= s.length()) {
        res.push_back(vector<string>(currentPartition));
        return;
    }

    for (int i = currentIndex; i < s.length(); i++) {
        if (isPalindrome(s, currentIndex, i)) {
            currentPartition.push_back(
                s.substr(currentIndex, i - currentIndex + 1));
            backtrack(s, res, currentPartition, i + 1);

            currentPartition.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> currentPartition;

    backtrack(s, res, currentPartition, 0);

    return res;
}

int main() {
    string s = "aab";
    cout << "String = " << s << "\n";

    vector<vector<string>> res = partition(s);

    cout << "Partitions = [";
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << "'" << res[i][j] << "'";
            if (j != res[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i != res.size() - 1) cout << ", ";
    }
    cout << "]\n";
    return 0;
}