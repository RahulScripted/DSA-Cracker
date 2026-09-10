// Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree. Note:

//     1 - The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
//     2 - A subtree of root is a tree consisting of root and all of its descendants.






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
public:
    pair<int, int> dfs(TreeNode* root, int& ans) {
        if (!root) return {0, 0};
        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        if (sum / count == root->val) ans++;
        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int result = sol.averageOfSubtree(root);
    cout << "Number of nodes where the value is equal to the average of its subtree: " << result << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}