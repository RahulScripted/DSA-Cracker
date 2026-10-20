// Given a root of binary search tree and two integers low, high. Return the sum of all elements that lie in inclusive range of [low, high].






#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution{
    public:
        int rangeSumBST(TreeNode* root, int low, int high){
            if (root == nullptr) return 0;
            if (root -> data < low) return rangeSumBST(root -> right, low, high);
            if (root -> data > high) return rangeSumBST(root -> left, low, high);
            return root -> data + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
        }
};

int main(){
    TreeNode* root = new TreeNode(10);
    root -> left = new TreeNode(5);
    root -> right = new TreeNode(15);
    root -> left -> left = new TreeNode(3);
    root -> left -> right = new TreeNode(7);
    root -> right -> right = new TreeNode(18);

    int low = 7, high = 15;
    Solution sol;
    cout << "Range Sum between " << low << " and " << high << " is : " << sol.rangeSumBST(root, low, high) << endl;
}