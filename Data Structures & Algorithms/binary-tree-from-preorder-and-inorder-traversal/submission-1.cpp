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
    TreeNode *process(vector<int>& preorder, int prestart, vector<int> &inorder, int instart, int inend)
    {
        if(instart>inend)
            return NULL;
        TreeNode *node=new TreeNode(preorder[prestart]);
        int index=-1;
        for(int i=instart;i<=inend;i++)
        {
            if(inorder[i]==preorder[prestart])
            {
                index=i;
                break;
            }
        }
        node->left=process(preorder, prestart+1, inorder, instart, index-1);
        node->right=process(preorder, prestart+1+index-instart, inorder, index+1, inend);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return process(preorder, 0, inorder, 0, inorder.size()-1);
    }
};
