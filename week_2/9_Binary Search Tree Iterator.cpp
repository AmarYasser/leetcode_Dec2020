/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
solution
- Perform Inorder traversal as it gives the values in the sorted order
- Access elements using current index
- Check current index against size of the values vector
TimeComplexity: O(N) for the inorder traversal inside constructor
hasNext and next are O(1)
Space Complexity: O(N) for storing N values

*/
class BSTIterator {
public:
    vector<int> values;
    int index = 0;
    void inorder(TreeNode* node, vector<int>& values) {
        if (node == NULL)
            return;
        inorder(node->left, values);
        values.push_back(node->val);
        inorder(node->right, values);
    }
    BSTIterator(TreeNode* root) {
        inorder(root, values);
    }
    
    int next() {
        return values[index++];
    }
    
    bool hasNext() {
        return index < values.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */