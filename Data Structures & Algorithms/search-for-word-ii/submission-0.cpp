class Solution {
public:
    class TrieNode
    {
        public:
            bool isLeaf;
            vector<TrieNode *> children;
            TrieNode()
            {
                isLeaf=false;
                children= vector<TrieNode *>(26);
            }
    };
    void insert(string &word)
    {
        TrieNode *temp=trie;
        for(char c:word)
        {
            if(!temp->children[c-'a'])
            {
                temp->children[c-'a']=new TrieNode();
            }
            temp=temp->children[c-'a'];
        }
        temp->isLeaf=true;
    }
    vector<pair<int,int>> dir={{-1,0}, {0,-1}, {1,0}, {0,1}};
    void process(vector<vector<char>>& board, int x, int y, unordered_set<string> &res, TrieNode *node, string &cur)
    {
        if(!node)
            return;
        cur+=board[x][y];
        node=node->children[board[x][y]-'a'];
        if(node && node->isLeaf)
        {
            res.insert(cur);
        }
        board[x][y]='.';
        for(pair<int,int> d:dir)
        {
            int x1=x+d.first;
            int y1=y+d.second;
            if(x1>=0 && y1>=0 && x1<board.size() && y1<board[0].size() && board[x1][y1]!='.')
            {
                process(board, x1, y1, res, node, cur);
            }
        }
        board[x][y]=cur[cur.length()-1];
        cur.pop_back();
    }
    TrieNode *trie;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        trie=new TrieNode();
        for(string word:words)
        {
            insert(word);
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                string cur;
                process(board, i, j, res, trie, cur);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
