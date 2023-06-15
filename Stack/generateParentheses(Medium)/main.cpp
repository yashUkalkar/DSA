#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/generate-parentheses/

void backtrackParentheses(vector<string>& res, string currentString,
                          int openCount, int closeCount, int maxParentheses) {

    if (currentString.length() == 2 * maxParentheses) {
        res.push_back(currentString);
        return;
    }

    if (openCount < maxParentheses)
        backtrackParentheses(res, currentString + "(", openCount + 1,
                             closeCount, maxParentheses);
    if (closeCount < openCount)
        backtrackParentheses(res, currentString + ")", openCount,
                             closeCount + 1, maxParentheses);
}

vector<string> generateParentheses(int n) {
    vector<string> res;
    backtrackParentheses(res, "", 0, 0, n);
    return res;
}

int main() {
    int numParentheses = 4;
    vector<string> res = generateParentheses(numParentheses);

    cout << "Answer : [";
    for (int i = 0; i < res.size(); i++) {
        cout << "'" << res[i] << "'";
        if (i != res.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}