#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/clone-graph/

// TODO: Implement verification code for the problem

//* Helpers
class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//* SOLUTION
Node* dfs(Node* node, unordered_map<Node*, Node*>& nodeMap) {
    if (nodeMap.find(node) != nodeMap.end()) return nodeMap[node];

    Node* copyNode = new Node(node->val);
    nodeMap[node] = copyNode;

    for (auto neighbor : node->neighbors)
        copyNode->neighbors.push_back(dfs(neighbor, nodeMap));

    return copyNode;
}
Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> nodeMap;

    return (!node ? NULL : dfs(node, nodeMap));
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node1);

    node1->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);

    node4->neighbors.push_back(node3);
    node3->neighbors.push_back(node4);

    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);

    return 0;
}