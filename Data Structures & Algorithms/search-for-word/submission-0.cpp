class Solution {
public:
    vector<pair<int,int>> dir={{-1,0}, {0,-1}, {1,0}, {0,1}};
    bool process(vector<vector<char>>& board, int x, int y, string &word, int index)
    {
        if(index==word.size()-1)
        {
            return board[x][y]==word[index];
        }
        if(board[x][y]!=word[index])
            return false;
        board[x][y]='.';
        for(pair<int,int> d:dir)
        {
            int x1=x+d.first;
            int y1=y+d.second;
            if(x1>=0 && y1>=0 && x1<board.size() && y1<board[0].size() && process(board, x1, y1, word, index+1))
            {
                return true;
            }
        }
        board[x][y]=word[index];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(process(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};
