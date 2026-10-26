class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> block(9);
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                    continue;
                if(rows[i].find(board[i][j])!=rows[i].end())
                    return false;
                rows[i].insert(board[i][j]);
                if(cols[j].find(board[i][j])!=cols[j].end())
                    return false;
                cols[j].insert(board[i][j]);
                int b=((i/3)*3)+j/3;
                if(block[b].find(board[i][j])!=block[b].end())
                    return false;
                block[b].insert(board[i][j]);
            }
        }
        return true;
    }
};
