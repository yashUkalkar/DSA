#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/add-two-numbers/

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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* head = dummy;

    int carry = 0;
    while (l1 || l2 || carry) {
        int v1 = 0, v2 = 0;

        if (l1) v1 = l1->val;
        if (l2) v2 = l2->val;

        int newVal = v1 + v2 + carry;

        carry = newVal / 10;
        int onesDigit = newVal % 10;

        head->next = new ListNode(onesDigit);
        head = head->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return dummy->next;
}

//* Driver code
int main() {
    vector<int> nums1 = {9, 9, 9, 9, 9, 9, 9};
    vector<int> nums2 = {9, 9, 9, 9};
    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);

    cout << "List 1 : ";
    displayList(l1);
    cout << "List 2 : ";
    displayList(l2);

    ListNode* res = addTwoNumbers(l1, l2);
    cout << "Sum List : ";
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