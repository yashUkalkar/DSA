#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/product-of-array-except-self/

vector<int> productExceptSelf(vector<int>& nums) {
    //! This is a more efficient way since we don't need to use more space for
    //! prefix and suffix arrays. Otherwise you may make separate prefix and
    //! suffix arrays and use them to calculate the product.
    int n = nums.size();
    vector<int> result(n);
    int pre = 1, post = 1;

    // Prefix products in the final array
    for (int i = 0; i < n; i++) {
        result[i] = pre;
        pre *= nums[i];
    }

    // Suffix products in the final array
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= post;
        post *= nums[i];
    }

    return result;
}

int main() {
    vector<int> v{2, 3, 7, 0};

    vector<int> ans = productExceptSelf(v);
    cout << "[ ";
    for (auto i : ans) cout << i << " ";
    cout << "]";

    return 0;
}