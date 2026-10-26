class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        vector<pair<int,int>> dir={{-1,0}, {0,-1}, {1,0}, {0,1}};

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='0')
                    continue;
                grid[i][j]='0';
                res++;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty())
                {
                    pair<int,int> p=q.front();
                    q.pop();
                    for(pair<int,int> d:dir)
                    {
                        int x=p.first+d.first;
                        int y=p.second+d.second;
                        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]=='1')
                        {
                            q.push({x,y});
                            grid[x][y]='0';
                        }
                    }
                }
            }
        }
        return res;
    }
};
