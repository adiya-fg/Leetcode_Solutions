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
#define mod 1000000007
class Solution {
public:
    
    long long ans=0;

    int dfs(TreeNode * curNode) {
        if(curNode==nullptr) return 0;
        return curNode->val + dfs(curNode->left) + dfs(curNode->right);
    }

    int findMax(TreeNode * curNode, int sum, long long& ans) {
        if(curNode==nullptr) return 0;
        int val1 = findMax(curNode->left,sum,ans);
        int val2 = findMax(curNode->right,sum,ans);
        //cout<<val1<<" : "<<val2<<" : "<<ans<<endl;
        long long maxVal1 = (1LL*(sum-val1)*val1);
        long long maxVal2 = (1LL*(sum-val2)*val2);
        ans = max(ans,max(maxVal1,maxVal2));
        return val1+val2+curNode->val;
    }

    int maxProduct(TreeNode* root) {
        int sum = dfs(root);
        //cout<<sum<<endl;
        findMax(root,sum,ans);
        return ans%mod;
    }
};