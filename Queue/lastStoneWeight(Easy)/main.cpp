#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/last-stone-weight/

//* SOLUTION
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;

    for (int i = 0; i < stones.size(); i++) {
        pq.push(stones[i]);
    }

    while (pq.size() > 1) {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if (y > x) {
            pq.push(y - x);
        }
    }

    if (pq.empty()) {
        return 0;
    }

    return pq.top();
}

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << "Stones = [";
    for (int i = 0; i < stones.size(); i++) {
        cout << stones[i];
        if (i != stones.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Last stone weight = " << lastStoneWeight(stones) << "\n";

    return 0;
}