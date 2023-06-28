#include <iostream>
#include <vector>
using namespace std;

//* Link -
//* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
TreeNode *findNodeInBST(TreeNode *root, int val);

//! ==============================================================

//* SOLUTION
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    while (root) {
        if (root->val < p->val && root->val < q->val)
            root = root->right;
        else if (root->val > p->val && root->val > q->val)
            root = root->left;
        else
            break;
    }
    return root;
}

//* Driver code
int main() {
    vector<string> nums = {"6", "2",    "8",    "0", "4", "7",
                           "9", "null", "null", "3", "5"};
    int p = 2;
    int q = 8;

    TreeNode *root = createBinaryTree(nums, 0, nums.size());
    cout << "Given Tree -> \n\n";
    displayTree(root);
    cout << endl;

    TreeNode *pNode = findNodeInBST(root, p);
    TreeNode *qNode = findNodeInBST(root, q);

    TreeNode *ancestor = lowestCommonAncestor(root, pNode, qNode);

    cout << ancestor->val;

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

TreeNode *findNodeInBST(TreeNode *root, int val) {
    if (!root || root->val == val) return root;

    if (root->val < val) return findNodeInBST(root->right, val);

    return findNodeInBST(root->left, val);
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