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
ListNode* reverseList(ListNode* head) {
    ListNode* prevNode = NULL;
    ListNode* nextNode = NULL;
    ListNode* current = head;

    while (current) {
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    }

    return prevNode;
}

int main() {
    vector<int> nums = {4, 1, 3, 7, 5};
    ListNode* head = createList(nums);

    cout << "Original List : ";
    displayList(head);

    ListNode* reversedList = reverseList(head);

    cout << "Reversed List : ";
    displayList(reversedList);

    return 0;
}