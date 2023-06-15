#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/container-with-most-water/

int maxArea(vector<int>& height) {
    int globalMaxArea = 0;
    int l = 0, r = height.size() - 1;

    while (l < r) {
        int currentArea = (r - l) * min(height[l], height[r]);
        globalMaxArea = max(currentArea, globalMaxArea);

        if (height[l] < height[r])
            l++;
        else
            r--;
    }

    return globalMaxArea;
}

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(heights);

    return 0;
}