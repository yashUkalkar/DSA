#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/merge-two-sorted-lists/

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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* node = new ListNode();
    ListNode* head = node;

    while (list1 && list2) {

        if (list1->val < list2->val) {
            node->next = list1;
            node = node->next;
            list1 = list1->next;
        } else {
            node->next = list2;
            node = node->next;
            list2 = list2->next;
        }
    }

    if (list1) node->next = list1;
    if (list2) node->next = list2;

    return head->next;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 7};
    vector<int> nums2 = {3, 7, 9, 10, 13, 15};
    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);

    cout << "List 1 : ";
    displayList(l1);
    cout << "List 2 : ";
    displayList(l2);

    ListNode* mergedList = mergeTwoLists(l1, l2);

    cout << "Merged List : ";
    displayList(mergedList);

    return 0;
}