#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
 
#define min(x,y) ((x<y) ? x : y)
#define max(x,y) ((x>y) ? x : y)

#define N 100001
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define INF 1000000000
 
using namespace std;

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> Q;

        Q.push(root);

        int mx = INT_MIN;
        int ans=0;
        int level=0;
        while(!Q.empty()) {
            
            level++;
            int sum = 0;
            int total=Q.size();

            while(total--){
                TreeNode * node = Q.front();
                if(node->left!=nullptr) Q.push(node->left);
                if(node->right!=nullptr) Q.push(node->right);
                sum += node->val;
                Q.pop();
            }
            if(mx < sum) {
                mx = sum;
                ans = level;
            }
        }
        return ans;
    }
};