#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// #include <queue>
using namespace std;

//* Link - https://leetcode.com/problems/find-if-path-exists-in-graph/

//* SOLUTION
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    // Create adjacency list/map for the graph
    unordered_map<int, vector<int>> adjacencyMap;
    for (auto i : edges) {
        adjacencyMap[i[0]].push_back(i[1]);
        adjacencyMap[i[1]].push_back(i[0]);
    }

    // Performing DFS to find node
    stack<int> st;
    unordered_set<int> visited;  // Required since this is undirected graph

    st.push(source);
    while (!st.empty()) {
        int currNode = st.top();
        st.pop();

        if (currNode == destination) return true;

        visited.insert(currNode);

        for (auto neighbor : adjacencyMap[currNode]) {
            if (visited.find(neighbor) == visited.end()) st.push(neighbor);
        }
    }

    return false;

    // Performing BFS to find node
    // queue<int> q;
    // unordered_set<int> visited;  // Required since this is undirected graph

    // q.push(source);
    // while (!q.empty()) {
    //     int currNode = q.front();
    //     q.pop();

    //     if (currNode == destination) return true;

    //     visited.insert(currNode);

    //     for (auto neighbor : adjacencyMap[currNode]) {
    //         if (visited.find(neighbor) == visited.end()) q.push(neighbor);
    //     }
    // }

    // return false;
}

int main() {
    int n = 6;
    cout << "Number of nodes = " << n << "\n";

    int source = 5, destination = 3;
    cout << "Source = " << source << "\n";
    cout << "Destination = " << destination << "\n";

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
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

    cout << (validPath(n, edges, source, destination) ? "True" : "False")
         << "\n";

    return 0;
}