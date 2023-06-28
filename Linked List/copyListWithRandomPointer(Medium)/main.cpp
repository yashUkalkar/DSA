//! TODO: Implement helper functions for this question

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/copy-list-with-random-pointer/

//* HELPERS
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* createList(vector<vector<int>>& nums);
void displayList(Node* head);

//! ==============================================================

//* SOLUTION
Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> nodeMap;

    Node* curr = head;
    while (curr) {
        nodeMap[curr] = new Node(curr->val);
        curr = curr->next;
    }

    curr = head;
    while (curr) {
        nodeMap[curr]->next = nodeMap[curr->next];
        nodeMap[curr]->random = nodeMap[curr->random];
        curr = curr->next;
    }

    return nodeMap[head];
}

//* Driver code
int main() {
    cout << "Result";
    return 0;
}

//! ==============================================================

//* HELPER DEFINITIONS
Node* createList(vector<vector<int>>& nums) {}
void displayList(Node* head) {}