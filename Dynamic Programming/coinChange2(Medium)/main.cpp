#include <iostream>
#include <map>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/coin-change-ii/

//* SOLUTION
int dfs(int& amount, vector<int>& coins, int index, int currAmount, int& n,
        map<pair<int, int>, int>& dp) {
    if (currAmount == amount) return 1;

    if (currAmount > amount) return 0;

    if (index == n) return 0;

    if (dp.find({index, currAmount}) != dp.end())
        return dp[{index, currAmount}];

    dp[{index, currAmount}] =
        dfs(amount, coins, index, currAmount + coins[index], n, dp) +
        dfs(amount, coins, index + 1, currAmount, n, dp);

    return dp[{index, currAmount}];
}
int change(int amount, vector<int>& coins) {
    int n = coins.size();

    //* Sub optimal solution
    // map<pair<int, int>, int> dp;

    // return dfs(amount, coins, 0, 0, n, dp);

    //* Memory optimized solution
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        vector<int> nextDP(amount + 1, 0);
        nextDP[0] = 1;

        for (int a = 1; a < amount + 1; a++) {
            nextDP[a] = dp[a];
            if (a - coins[i] >= 0) nextDP[a] += nextDP[a - coins[i]];
        }
        dp = nextDP;
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    cout << "Coins = [";
    for (int i = 0; i < coins.size(); i++) {
        cout << coins[i];
        if (i != coins.size() - 1) cout << ", ";
    }
    cout << "]\n";

    int amount = 5;
    cout << "Amount = " << amount << "\n";

    cout << "Number of combinations = " << change(amount, coins);

    return 0;
}