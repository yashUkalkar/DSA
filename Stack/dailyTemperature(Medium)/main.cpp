#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/daily-temperatures/

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);
    stack<int> st;

    for (int i = 0; i < temperatures.size(); i++) {
        while (!st.empty() && (temperatures[i] > temperatures[st.top()])) {
            int dayIndex = st.top();
            res[dayIndex] = i - dayIndex;
            st.pop();
        }

        st.push(i);
    }

    return res;
}

int main() {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temp);

    cout << "Answer : [";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}