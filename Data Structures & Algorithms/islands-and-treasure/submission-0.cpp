class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
       vector<pair<int,int>> dir={{-1,0}, {0,-1}, {1,0}, {0,1}};
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        int dist=1;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(pair<int,int> d:dir)
                {
                    int x=p.first+d.first;
                    int y=p.second+d.second;
                    if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==INT_MAX)
                    {
                        q.push({x,y});
                        grid[x][y]=dist;
                    }
                }
            }
            dist++;
        }
    }
};
