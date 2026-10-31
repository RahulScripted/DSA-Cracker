// Given the root of an N-ary tree, compute the length of its diameter. The diameter is defined as the length of the longest path between any two nodes in the tree. (Nary-Tree input serialization is represented in their level order traversal, with each group of children separated by a null value.)







#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    vector<TreeNode*> children;

    TreeNode() {}
    TreeNode(int _val) {
        val = _val;
    }

    TreeNode(int _val, vector<TreeNode*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int ans;

    int diameter(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }


    int dfs(TreeNode* root) {
        if (!root) return 0;
        int m1 = 0, m2 = 0;
        for (TreeNode* child : root->children) {
            int t = dfs(child);
            if (t > m1) {
                m2 = m1;
                m1 = t;
            } else if (t > m2) m2 = t;
        }
        ans = max(ans, m1 + m2);
        return 1 + m1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->children.push_back(new TreeNode(2));
    root->children.push_back(new TreeNode(3));
    root->children.push_back(new TreeNode(4));
    root->children[0]->children.push_back(new TreeNode(5));
    root->children[0]->children.push_back(new TreeNode(6));

    Solution sol;
    int diameter = sol.diameter(root);
    cout << "Diameter of the N-ary tree: " << diameter << endl;
}
