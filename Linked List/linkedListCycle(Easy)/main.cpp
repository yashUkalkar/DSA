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
ListNode* createListWithCycle(vector<int>& nums, int pos);
void displayList(ListNode* head);
void displayListWithCycle(ListNode* head, int length);

//! ==============================================================

//* SOLUTION
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

//* Driver code
int main() {
    vector<int> nums = {3, 2, 0, -4};
    int pos = 1;
    ListNode* head = createListWithCycle(nums, pos);

    cout << "List : ";
    displayListWithCycle(head, nums.size());
    cout << "Position of cycle = " << pos << endl;

    if (hasCycle(head))
        cout << "True";
    else
        cout << "False";

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

ListNode* createListWithCycle(vector<int>& nums, int pos) {
    ListNode* node = new ListNode();
    ListNode* head = node;
    ListNode* cycleToNode = nullptr;

    ListNode* n = nullptr;
    for (int i = 0; i < nums.size(); i++) {
        n = new ListNode(nums[i]);
        node->next = n;
        node = n;

        if (i == pos) cycleToNode = n;
    }
    n->next = cycleToNode;

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

void displayListWithCycle(ListNode* head, int length) {
    while (length--) {
        cout << head->val;
        if (length != 0) cout << "->";
        head = head->next;
    }
    cout << endl;
}