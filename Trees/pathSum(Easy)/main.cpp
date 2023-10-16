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
bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root || targetSum < root->val) return false;

    if (targetSum == root->val) {
        cout << root->val;
        return true;
    }

    cout << root->val << "->";

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

//* Driver code
int main() {
    vector<string> nums = {"5", "4", "8",    "11",   "null", "13", "4",
                           "7", "2", "null", "null", "null", "1"};
    int targetSum = 23;

    TreeNode *root = createBinaryTree(nums, 0, nums.size());
    cout << "Given Tree -> \n\n";
    displayTree(root);
    cout << endl;

    cout << "Path taken = ";  // Valid only if path sum exists
    cout << (hasPathSum(root, targetSum) ? "\nTrue" : "\nFalse");

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