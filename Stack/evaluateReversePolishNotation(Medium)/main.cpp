#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/evaluate-reverse-polish-notation/

int evalRPN(vector<string>& tokens) {
    stack<string> st;

    for (auto i : tokens) {
        if (i == "+" || i == "-" || i == "*" || i == "/") {
            // Extract operands
            int a = stoi(st.top());
            st.pop();
            int b = stoi(st.top());
            st.pop();

            // Perform operation
            int res;
            if (i == "+")
                res = a + b;
            else if (i == "-")
                res = b - a;
            else if (i == "*")
                res = a * b;
            else
                res = b / a;

            // Add to stack
            st.push(to_string(res));
        } else
            st.push(i);
    }

    return stoi(st.top());
}

int main() {
    vector<string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                             "/",  "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens);

    return 0;
}