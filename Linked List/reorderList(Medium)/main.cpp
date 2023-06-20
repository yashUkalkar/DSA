#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/reverse-linked-list/

//* HELPERS
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* createList(vector<int>& nums) {
    ListNode* node = new ListNode();
    ListNode* head = node;

    for (auto i : nums) {
        ListNode* n = new ListNode(i);
        node->next = n;
        node = n;
    }

    return head->next;
}
void displayList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

//* SOLUTION
void reorderList(ListNode* head) {
    // Find mid point of list
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* midNode = slow->next;
    slow->next = nullptr;

    // Reverse 2nd half of list
    ListNode* prevNode = nullptr;
    while (midNode) {
        ListNode* nextNode = midNode->next;
        midNode->next = prevNode;
        prevNode = midNode;
        midNode = nextNode;
    }

    // Merge two halves
    ListNode* tail = prevNode;
    while (tail) {
        ListNode* temp1 = head->next;
        ListNode* temp2 = tail->next;
        head->next = tail;
        tail->next = temp1;

        head = temp1;
        tail = temp2;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* l = createList(nums);

    cout << "Original List : ";
    displayList(l);

    reorderList(l);
    cout << "Reordered List : ";
    displayList(l);

    return 0;
}