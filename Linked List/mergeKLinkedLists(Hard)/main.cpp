#include <iostream>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/merge-k-sorted-lists/

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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* head = dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            head->next = l1;
            l1 = l1->next;
        } else {
            head->next = l2;
            l2 = l2->next;
        }

        head = head->next;
    }

    if (l1) head->next = l1;
    if (l2) head->next = l2;

    return dummy->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (!lists.size()) return nullptr;

    while (lists.size() > 1) {
        vector<ListNode*> mergedLists;

        for (int i = 0; i < lists.size(); i += 2) {
            ListNode* l1 = lists[i];
            ListNode* l2 = nullptr;
            if (i + 1 < lists.size()) {
                l2 = lists[i + 1];
            }

            mergedLists.push_back(mergeTwoLists(l1, l2));
        }

        lists = mergedLists;
    }

    return lists[0];
}

//* Driver code
int main() {
    vector<vector<int>> nums = {{1, 4, 5}, {1, 3, 4}, {2, 6}};

    vector<ListNode*> lists;
    for (auto i : nums) {
        ListNode* l = createList(i);
        lists.push_back(l);
    }

    cout << "Lists : \n";
    for (auto i : lists) displayList(i);

    ListNode* res = mergeKLists(lists);
    cout << "Sorted list : ";
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