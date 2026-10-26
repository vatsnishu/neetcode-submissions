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

class Codec {
public:

    void pserialize(TreeNode *root, string &res)
    {
        if(!root)
        {
            res+="NULL#";
            return;
        }
        res+=to_string(root->val)+"#";
        pserialize(root->left, res);
        pserialize(root->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        pserialize(root, res);
        return res.substr(0, res.length()-1);
    }

    vector<string> parse(string &data)
    {
        int start=0;
        vector<string> res;
        while(1)
        {
            int end=data.find("#", start);
            string str;
            if(end==-1)
            {
                str=data.substr(start);
            }
            else
            {
                str=data.substr(start, end-start);
            }
            res.push_back(str);
            if(end==-1)
                break;
            start=end+1;
        }
        return res;
    }

    TreeNode *pdeserialize(vector<string> &vec, int& index)
    {
        if(vec[index]=="NULL")
            return NULL;
        TreeNode *node=new TreeNode(stoi(vec[index]));
        node->left=pdeserialize(vec, ++index);
        node->right=pdeserialize(vec, ++index);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec=parse(data);
        int index=0;
        return pdeserialize(vec, index);
    }
};
