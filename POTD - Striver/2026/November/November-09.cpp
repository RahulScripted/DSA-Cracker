// Given the root of a binary tree, return the length of the longest consecutive path in the tree. A consecutive path is a path where the values of the consecutive nodes in the path differ by one. This path can be either increasing or decreasing.






#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int max_len = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        int inc = 1, dec = 1;
        if (node->left) {
            auto left_res = dfs(node->left);
            if (node->left->val == node->val + 1) inc = max(inc, left_res.first + 1);
            else if (node->left->val == node->val - 1) dec = max(dec, left_res.second + 1);
        }

        if (node->right) {
            auto right_res = dfs(node->right);
            if (node->right->val == node->val + 1) inc = max(inc, right_res.first + 1);
            else if (node->right->val == node->val - 1) dec = max(dec, right_res.second + 1);
        }

        max_len = max(max_len, inc + dec - 1);
        return {inc, dec};
    }

public:
    int longestConsecutive(TreeNode* root) {
        max_len = 0;
        dfs(root);
        return max_len;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Length of the longest consecutive path: " << sol.longestConsecutive(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}