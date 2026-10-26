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
    int find(TreeNode *root, int &res)
    {
        if(!root)
            return INT_MIN;
        int left=max(find(root->left, res), 0);
        int right=max(find(root->right, res), 0);
        res=max(res, root->val+left+right);
        return root->val+max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        res=max(res, find(root, res));
        return res;
    }
};
