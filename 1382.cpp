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
    
    vector<int> vals;
    void visitTree(TreeNode* root) {
        if(root==nullptr) return ;
        vals.push_back(root->val);
        visitTree(root->left);
        visitTree(root->right);
    }

    TreeNode * dfs(int leftIndex, int rightIndex, vector<int> vals) {
        if(leftIndex>rightIndex) return nullptr;
        cout<<leftIndex<<" : "<<rightIndex<<endl;
        if(leftIndex==rightIndex) return new TreeNode(vals[leftIndex]);
        int mid = (leftIndex+rightIndex)/2;
        TreeNode * newRoot = new TreeNode(vals[mid]);
        newRoot->left = dfs(leftIndex,mid-1,vals);
        newRoot->right = dfs(mid+1,rightIndex,vals);
        return newRoot;
    }

    TreeNode* balanceBST(TreeNode* root) {
        
        visitTree(root);
        sort(vals.begin(),vals.end());
        // cout<<vals.size()<<endl;
        // for(auto val : vals) {
        //     cout<<val<<" ";
        // }
        // cout<<endl;
        return dfs(0,vals.size()-1,vals);
    }
};


/*
Approach 2: Day-Stout-Warren Algorithm / In-Place Balancing
Intuition
Note: This approach is very advanced and would not be expected in an interview. 
We have included it for completeness.
*/
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return nullptr;

        // Step 1: Create the backbone (vine)
        // Temporary dummy node
        TreeNode* vineHead = new TreeNode(0);
        vineHead->right = root;
        TreeNode* current = vineHead;
        while (current->right) {
            if (current->right->left) {
                rightRotate(current, current->right);
            } else {
                current = current->right;
            }
        }

        // Step 2: Count the nodes
        int nodeCount = 0;
        current = vineHead->right;
        while (current) {
            ++nodeCount;
            current = current->right;
        }

        // Step 3: Create a balanced BST
        int m = pow(2, floor(log2(nodeCount + 1))) - 1;
        makeRotations(vineHead, nodeCount - m);
        while (m > 1) {
            m /= 2;
            makeRotations(vineHead, m);
        }

        TreeNode* balancedRoot = vineHead->right;
        // Delete the temporary dummy node
        delete vineHead;
        return balancedRoot;
    }

private:
    // Function to perform a right rotation
    void rightRotate(TreeNode* parent, TreeNode* node) {
        TreeNode* tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;
        parent->right = tmp;
    }

    // Function to perform a left rotation
    void leftRotate(TreeNode* parent, TreeNode* node) {
        TreeNode* tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;
        parent->right = tmp;
    }

    // Function to perform a series of left rotations to balance the vine
    void makeRotations(TreeNode* vineHead, int count) {
        TreeNode* current = vineHead;
        for (int i = 0; i < count; ++i) {
            TreeNode* tmp = current->right;
            leftRotate(current, tmp);
            current = current->right;
        }
    }
};

////

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
    TreeNode* balanceBST(TreeNode* root) {
		vector<int> ordered_list;
		inordered_traversal(root, ordered_list);
		return balanceBST_Helper(ordered_list, 0, ordered_list.size()-1);
    }
	
private:
	void inordered_traversal(TreeNode* root, vector<int>&nodes) {
		if(root==nullptr) return ;
		inordered_traversal(root->left,nodes);
		nodes.push_back(root->val);
		inordered_traversal(root->right,nodes);
	}
	
	TreeNode* balanceBST_Helper(vector<int>&nodes, int start, int end) {
		if(start>end) return nullptr;
		
		int mid_index = start + ((end - start) >> 1);
		
        TreeNode * temp = new TreeNode();
		temp->val = nodes[mid_index];
		
		temp->left = balanceBST_Helper(nodes, start, mid_index-1);
		temp->right = balanceBST_Helper(nodes, mid_index+1, end);
		
		return temp;
	}
};