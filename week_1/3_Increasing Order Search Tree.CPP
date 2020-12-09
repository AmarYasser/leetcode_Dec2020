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
class Solution {
public:
    
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) return NULL;
        vector<int> nodes;
        stack<TreeNode*> st;     
        TreeNode *p = root;
        
        // Store valuees 
        /*BINARY SEARCH TREE INORDER TRAVERSAL USING ITERATIVE DEPTH FIRST SEARCH ALGORITHMS
We can replace the recursion with manual stacks. We push the left nodes to the stack at priority, and navigate to the right nodes then.*/
        while (st.size() > 0 || p) {         
            while (p) {
                st.push(p);    
                p = p->left;
            }                        
            p = st.top();
            st.pop();
            nodes.push_back(p->val);
            p = p->right;
        }
        
        TreeNode *ans = new TreeNode(-1);
        p = ans;
        for (const auto &n: nodes) {
            p->right = new TreeNode(n);
            p = p->right;
        }
        return ans->right;        
    }
    
    
};