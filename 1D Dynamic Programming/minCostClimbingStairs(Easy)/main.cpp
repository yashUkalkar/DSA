#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/min-cost-climbing-stairs/

//* SOLUTION
int minCostClimbingStairs(vector<int>& cost) {
    // Bottom-Up DP approach
    cost.push_back(0);

    for (int i = cost.size() - 3; i >= 0; i--) {
        cost[i] += min(cost[i + 1], cost[i + 2]);
    }

    return min(cost[0], cost[1]);
}

int main() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Cost = [";
    for (int i = 0; i < cost.size(); i++) {
        cout << cost[i];
        if (i != cost.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Minimum cost = " << minCostClimbingStairs(cost) << "\n";

    return 0;
}