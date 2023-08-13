#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//* Link -
//* https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

void displayTree(TreeNode *root);

//! ==============================================================

//* SOLUTION
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) return nullptr;

    TreeNode *root = new TreeNode(preorder[0]);

    //* Finding root position in inorder array
    int rootInorderIndex;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == preorder[0]) {
            rootInorderIndex = i;
            break;
        }
    }

    vector<int> leftPreorder = {preorder.begin() + 1,
                                preorder.begin() + rootInorderIndex + 1};
    vector<int> leftInorder = {inorder.begin(),
                               inorder.begin() + rootInorderIndex};

    root->left = buildTree(leftPreorder, leftInorder);

    vector<int> rightPreorder = {preorder.begin() + rootInorderIndex + 1,
                                 preorder.end()};
    vector<int> rightInorder = {inorder.begin() + rootInorderIndex + 1,
                                inorder.end()};

    root->right = buildTree(rightPreorder, rightInorder);

    return root;
}

//* Driver code
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    cout << "Preorder = [";
    for (int i = 0; i < preorder.size(); i++) {
        cout << preorder[i];
        if (i != preorder.size() - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Inorder = [";
    for (int i = 0; i < inorder.size(); i++) {
        cout << inorder[i];
        if (i != inorder.size() - 1) cout << ", ";
    }
    cout << "]\n\n";

    TreeNode *tree = buildTree(preorder, inorder);

    cout << "Tree -> \n";
    displayTree(tree);

    cout << endl;

    return 0;
}

//! ==============================================================

//* HELPER DEFINITIONS

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