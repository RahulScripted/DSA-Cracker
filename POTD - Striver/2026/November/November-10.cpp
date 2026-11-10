// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

//     1 - BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
//     2 - boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
//     3 - int next() Moves the pointer to the right, then returns the number at the pointer.

// Notice that by initializing the pointer to a non-existent smallest number, the first call to the next() will return the smallest element in the BST. Assume that the next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when the next() is called.







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

class BSTIterator{
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        if (topNode->right != nullptr) pushLeft(topNode->right);
        return topNode->data;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator iterator(root);
    
    cout << iterator.next() << endl;
    cout << iterator.next() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.next() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.next() << endl;
    cout << iterator.hasNext() << endl;
    cout << iterator.next() << endl;
    cout << iterator.hasNext() << endl;
}