#include <iostream>
#include <vector>
using namespace std;

//* Link -

//* HELPERS
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

TreeNode *createBinaryTree(vector<string> &vec, int i, int n);
void displayTree(TreeNode *root);

//! ==============================================================

//* SOLUTION
bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;

    if (p && q && (p->val == q->val)) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    return false;
}
bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!subRoot) return true;
    if (!root) return false;

    if (isSameTree(root, subRoot)) return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    vector<string> nums1 = {"3", "4", "5", "1", "2"};
    vector<string> nums2 = {"4", "1", "2"};

    TreeNode *root = createBinaryTree(nums1, 0, nums1.size());
    TreeNode *subRoot = createBinaryTree(nums2, 0, nums2.size());

    cout << "Main Tree -> \n\n";
    displayTree(root);
    cout << endl;

    cout << "Sub Tree -> \n\n";
    displayTree(subRoot);
    cout << endl;

    if (isSubtree(root, subRoot))
        cout << "True";
    else
        cout << "False";

    return 0;
}

//! ==============================================================

//* HELPER DEFINITIONS

TreeNode *createBinaryTree(vector<string> &vec, int i, int n) {
    TreeNode *root = nullptr;

    if ((i < n) && (vec[i] != "null")) {
        root = new TreeNode(stoi(vec[i]));

        root->left = createBinaryTree(vec, 2 * i + 1, n);

        root->right = createBinaryTree(vec, 2 * i + 2, n);
    }

    return root;
}

//* Displaying tree
struct Trunk {
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};
// Helper function to print branches of the binary tree
void showTrunks(Trunk *p) {
    if (p == nullptr) {
        return;
    }

    showTrunks(p->prev);
    cout << p->str;
}
void printTree(TreeNode *root, Trunk *prev, bool isLeft) {
    if (root == nullptr) {
        return;
    }

    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev) {
        trunk->str = "———";
    } else if (isLeft) {
        trunk->str = ".———";
        prev_str = "   |";
    } else {
        trunk->str = "`———";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->val << endl;

    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}
void displayTree(TreeNode *root) { printTree(root, nullptr, false); }