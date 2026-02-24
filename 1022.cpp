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
    int dfs(TreeNode * u, int sum) {
        // is the leaf node 
        if(u->left==nullptr && u->right==nullptr) return sum;
        int res = 0;
        if(u->left!=nullptr)
            res += dfs(u->left, sum*2 + u->left->val);
        if(u->right!=nullptr)
            res += dfs(u->right, sum*2 + u->right->val);
        return res;
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,root->val);    
    }
};