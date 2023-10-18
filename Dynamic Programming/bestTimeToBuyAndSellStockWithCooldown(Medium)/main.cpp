#include <iostream>
#include <map>
#include <vector>
using namespace std;

//* Link -
//* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

//* SOLUTION
int dfs(int index, bool buying, vector<int>& prices,
        map<pair<int, bool>, int>& dp, int n) {
    if (index >= n) return 0;

    if (dp.find({index, buying}) != dp.end()) return dp[{index, buying}];

    int profitOnCooldown = dfs(index + 1, buying, prices, dp, n);
    if (buying) {
        int profitOnBuy = dfs(index + 1, false, prices, dp, n) - prices[index];
        dp[{index, buying}] = max(profitOnBuy, profitOnCooldown);
    } else {
        int profitOnSell = dfs(index + 2, true, prices, dp, n) + prices[index];
        dp[{index, buying}] = max(profitOnSell, profitOnCooldown);
    }

    return dp[{index, buying}];
}
int maxProfit(vector<int>& prices) {
    map<pair<int, bool>, int> dp;
    int n = prices.size();

    return dfs(0, true, prices, dp, n);
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Prices = [";
    for (int i = 0; i < prices.size(); i++) {
        cout << prices[i];
        if (i != prices.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Max profit = " << maxProfit(prices) << "\n";

    return 0;
}