#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/find-center-of-star-graph/

//* SOLUTION
int findCenter(vector<vector<int>>& edges) {
    unordered_map<int, int> nodeConnections;
    int numNodes = 0;
    int res = edges[0][0];

    for (auto i : edges) {
        if (nodeConnections.find(i[0]) == nodeConnections.end()) numNodes++;
        if (nodeConnections.find(i[1]) == nodeConnections.end()) numNodes++;

        nodeConnections[i[0]]++;
        nodeConnections[i[1]]++;
    }

    for (auto i : nodeConnections) {
        if (i.second == numNodes - 1) {
            res = i.first;
            break;
        }
    }

    return res;
}

int main() {
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 5}, {1, 4}};
    cout << "Edges = [";
    for (int i = 0; i < edges.size(); i++) {
        cout << "[";
        for (int j = 0; j < edges[i].size(); j++) {
            cout << edges[i][j];
            if (j != edges[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i != edges.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Central node = " << findCenter(edges) << "\n";

    return 0;
}