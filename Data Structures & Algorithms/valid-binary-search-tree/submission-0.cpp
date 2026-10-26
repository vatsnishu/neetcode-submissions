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
    bool isValidBST(TreeNode* root, long long int low=(long long int)INT_MIN-1, long long int high=(long long int)INT_MAX+1) {
        if(!root)
            return true;
        if(root->val<=low || root->val>=high)
            return false;
        return isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high);
    }
};
