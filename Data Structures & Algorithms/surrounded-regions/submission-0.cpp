class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{-1,0}, {0,-1}, {1,0}, {0,1}};
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                board[i][0]='E';
            }
            if(board[0].size()>1 && board[i][board[0].size()-1]=='O')
            {
                q.push({i, board[0].size()-1});
                board[i][board[0].size()-1]='E';
            }
        }

        for(int i=1;i<board[0].size()-1;i++)
        {
            if(board[0][i]=='O')
            {
                q.push({0,i});
                board[0][i]='E';
            }
            if(board.size()>1 && board[board.size()-1][i]=='O')
            {
                q.push({board.size()-1, i});
                board[board.size()-1][i]='E';
            }
        }

        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();

            for(pair<int,int> d:dir)
            {
                int x=p.first+d.first;
                int y=p.second+d.second;

                if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]=='O' && board[x][y]=='O')
                {
                    q.push({x, y});
                    board[x][y]='E';
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='E')
                    board[i][j]='O';
            }
        }
    }
};
