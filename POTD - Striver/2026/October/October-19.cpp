// Given root of the binary tree, return its maximum depth.A binary tree's maximum depth is number of nodes along the longest path from root node down to the farthest node.





#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftHeight = maxDepth(root -> left);
        int rightHeight = maxDepth(root -> right);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int depth = solution.maxDepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;
}