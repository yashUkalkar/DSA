#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

//* Link - https://leetcode.com/problems/valid-parentheses/

bool validParentheses(string s) {
    unordered_map<char, char> bracketMap = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

    stack<int> st;

    for (auto i : s) {
        if ((i == '(') || (i == '{') || (i == '['))
            st.push(i);
        else if (st.empty() || (bracketMap[st.top()] != i))
            return false;
        else
            st.pop();
    }

    return st.empty();
}

int main() {
    string s = "[{{([()])}}]";

    if (validParentheses(s))
        cout << "True";
    else
        cout << "False";

    return 0;
}