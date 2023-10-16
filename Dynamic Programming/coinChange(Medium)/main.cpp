#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/coin-change/

//* SOLUTION
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int amt = 1; amt <= amount; amt++) {
        for (auto coin : coins) {
            if (amt - coin >= 0) {
                dp[amt] = min(dp[amt], 1 + dp[amt - coin]);
            }
        }
    }

    return dp[amount] != INT_MAX ? dp[amount] : -1;
}

int main() {
    vector<int> coins = {1, 2, 5};
    cout << "Coins = [";
    for (int i = 0; i < coins.size(); i++) {
        cout << coins[i];
        if (i != coins.size() - 1) cout << ", ";
    }
    cout << "]\n";

    int amount = 11;
    cout << "Amount = " << amount << "\n";

    cout << "Min coins required = " << coinChange(coins, amount);

    return 0;
}