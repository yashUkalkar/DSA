#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//* Link - https://leetcode.com/problems/binary-tree-level-order-traversal/

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
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty()) {
        vector<int> levelList;
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            TreeNode *node = q.front();
            q.pop();

            if (node) {
                levelList.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
        if (!levelList.empty()) res.push_back(levelList);
    }

    return res;
}

//* Driver code
int main() {
    vector<string> nums = {"3", "9", "20", "null", "null", "15", "7"};

    TreeNode *root = createBinaryTree(nums, 0, nums.size());
    cout << "Given Tree -> \n\n";
    displayTree(root);
    cout << endl;

    vector<vector<int>> res = levelOrder(root);
    cout << "Level order : [ ";
    for (auto i : res) {
        cout << "[";
        for (auto j : i) cout << j << ",";
        cout << "] ";
    }
    cout << "]\n";

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