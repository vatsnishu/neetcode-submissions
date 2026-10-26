class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        vector<pair<int,int>> dir={{-1,0}, {0,-1}, {1,0}, {0,1}};

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    continue;
                int size=0;
                queue<pair<int,int>> q;
                q.push({i,j});
                grid[i][j]=0;
                while(!q.empty())
                {
                    pair<int,int> p=q.front();
                    q.pop();
                    size++;
                    for(pair<int,int> d:dir)
                    {
                        int x=p.first+d.first;
                        int y=p.second+d.second;
                        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1)
                        {
                            q.push({x,y});
                            grid[x][y]=0;
                        }
                    }
                    res=max(res, size);
                }
            }
        }
        return res;
    }
};
