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
    int find(TreeNode *root, int maxtillnow)
    {
        if(!root)
            return 0;
        int res=0;
        if(root->val>=maxtillnow)
        {
            res++;
        }
        return res+find(root->left, max(root->val, maxtillnow))+find(root->right, max(root->val, maxtillnow));
    }
    int goodNodes(TreeNode* root) {
        
        return find(root, root->val);
    }
};
