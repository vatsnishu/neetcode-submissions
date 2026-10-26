class Solution {
public:
    struct TrieNode 
    {
        bool isLeaf=false;
        TrieNode *children[26];
    };

    TrieNode *root=new TrieNode();
    vector<pair<int,int>> dir={{-1,0}, {0,-1}, {1,0}, {0,1}};
    vector<string> res;

    void insert(string &str)
    {
        TrieNode *node=root;
        for(char c:str)
        {
            if(!node->children[c-'a'])
            {
                node->children[c-'a']=new TrieNode();
            }
            node=node->children[c-'a'];
        }
        node->isLeaf=true;
    }

    void dfs(vector<vector<char>> &board, int x, int y, TrieNode *node, string &path)
    {
        char c=board[x][y];
        int index=c-'a';
        if(!node->children[index])
            return;

        node=node->children[index];
        path.push_back(c);
        board[x][y]='.';

        if(node->isLeaf)
        {
            res.push_back(path);
            node->isLeaf=false;
        }
            
        for(auto [ix, iy]:dir)
        {
            int x1=x+ix;
            int y1=y+iy;
            if(x1>=0 && y1>=0 && x1<board.size() && y1<board[0].size() && board[x1][y1]!='.')
            {
                dfs(board, x1, y1, node, path);
            }
        }

        path.pop_back();
        board[x][y]=c;
        
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word:words)
        {
            insert(word);
        }
        string path;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                dfs(board, i, j, root, path);
            }
        }
        return res;
    }
};
