#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(vector<int>& prices) {
    int profit = 0;

    int l = 0, r = 1;
    while (r < prices.size()) {
        int currentProfit = prices[r] - prices[l];
        if (currentProfit > 0) {
            profit = max(profit, currentProfit);
        } else {
            l = r;
        }

        r++;
    }

    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);

    return 0;
}