#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/parallel-courses-iii/

//* SOLUTION
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    unordered_map<int, vector<int>> adjacencyMap;
    vector<int> inDegree(n, 0);
    vector<int> maxTime(n);
    queue<int> q;

    // Create adjacency list/map
    for (auto i : relations) {
        adjacencyMap[i[0] - 1].push_back(i[1] - 1);
        inDegree[i[1] - 1]++;
    }

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) q.push(i);
        maxTime[i] = time[i];
    }

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();

        for (auto neighbor : adjacencyMap[currNode]) {
            maxTime[neighbor] =
                max(maxTime[neighbor], maxTime[currNode] + time[neighbor]);
            inDegree[neighbor]--;

            if (inDegree[neighbor] == 0) q.push(neighbor);
        }
    }

    int ans = 0;
    for (auto i : maxTime) {
        ans = max(ans, i);
    }

    return ans;
}

int main() {
    int n = 3;
    cout << "\nNumber of nodes = " << n << "\n";

    vector<vector<int>> relations = {{1, 3}, {2, 3}};
    cout << "Relations = [";
    for (int i = 0; i < relations.size(); i++) {
        cout << "[";
        for (int j = 0; j < relations[i].size(); j++) {
            cout << relations[i][j];
            if (j != relations[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i != relations.size() - 1) cout << ", ";
    }
    cout << "]\n";

    vector<int> time = {3, 2, 5};
    cout << "Time = [";
    for (int i = 0; i < n; i++) {
        cout << time[i];
        if (i != n - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Minimum time required = " << minimumTime(n, relations, time)
         << " months\n";

    return 0;
}