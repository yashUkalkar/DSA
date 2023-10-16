#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/maximum-product-subarray/

//* SOLUTION
int maxProduct(vector<int>& nums) {
    int ans = nums[0];

    int leftProduct = 1, rightProduct = 1;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        leftProduct = (leftProduct == 0 ? 1 : leftProduct);
        rightProduct = (rightProduct == 0 ? 1 : rightProduct);

        leftProduct *= nums[i];
        rightProduct *= nums[n - i - 1];

        ans = max(ans, max(leftProduct, rightProduct));
    }

    return ans;
}

int main() {
    vector<int> nums = {-2, 0, -1};
    cout << "Input = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Max product = " << maxProduct(nums) << "\n";
    return 0;
}