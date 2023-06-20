#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/trapping-rain-water/

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    int currentMax = 0;
    // Calculate max height to left
    for (int i = 0; i < n; i++) {
        leftMax[i] = currentMax;
        if (height[i] > currentMax) currentMax = height[i];
    }
    currentMax = 0;
    // Calculate max height to right
    for (int i = n - 1; i >= 0; i--) {
        rightMax[i] = currentMax;
        if (height[i] > currentMax) currentMax = height[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res += max(0, min(leftMax[i], rightMax[i]) - height[i]);
    }

    return res;
}

/*  ** SOLUTION LOGIC **

    * Number of water blocks/units that can be trapped above current block
    * of height = height[i] is calculated as follows -

    * numBlocks = min(leftMax[i], rightMax[i]) - height[i]

    * Say leftMax[i] = rightMax[i] = 0, height[i] = 1
    * then we get numBlocks = min(0, 0) - 1 = 0 - 1 = -1
    * Since this is not possible, we store either positive result or 0
    *
    * numBlocks = max(0, min(leftMax[i], rightMax[i]) - height[i])
*/

int main() {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(heights);

    return 0;
}