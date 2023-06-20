#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/largest-rectangle-in-histogram/

int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    stack<pair<int, int>> st;

    for (int i = 0; i < heights.size(); i++) {
        int startIndex = i;

        while (!st.empty() and (heights[i] < st.top().second)) {
            int index = st.top().first;
            int height = st.top().second;

            int currentMaxArea = height * (i - index);
            maxArea = max(maxArea, currentMaxArea);
            startIndex = index;

            st.pop();
        }

        st.push(pair<int, int>{startIndex, heights[i]});
    }

    // Check area for heights remaining in stack
    while (!st.empty()) {
        int index = st.top().first;
        int height = st.top().second;

        int currentMaxArea = height * (heights.size() - index);
        maxArea = max(maxArea, currentMaxArea);

        st.pop();
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights);

    return 0;
}