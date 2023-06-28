#include <iostream>
#include <vector>
using namespace std;

//* Link -

//* HELPERS
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createList(vector<int>& nums);
void displayList(ListNode* head);

//! ==============================================================

//* SOLUTION
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);

    ListNode* leftPtr = dummy;
    ListNode* rightPtr = head;
    while (n-- && rightPtr) rightPtr = rightPtr->next;

    while (rightPtr) {
        leftPtr = leftPtr->next;
        rightPtr = rightPtr->next;
    }

    leftPtr->next = leftPtr->next->next;

    return dummy->next;
}

//* Driver code
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = createList(nums);
    int n = 2;

    cout << "List : ";
    displayList(head);
    cout << "N = " << n << endl;

    ListNode* res = removeNthFromEnd(head, n);
    cout << "Updated List : ";
    displayList(res);

    return 0;
}

//! ==============================================================

//* HELPER DEFINITIONS

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