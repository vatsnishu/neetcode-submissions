class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir={{-1,0}, {0,-1}, {1,0}, {0,1}};
        queue<pair<int,int>> q;
        int res=0;
        int freshoranges=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    freshoranges++;
                }
            }
        }
        int time=0;
        while(!q.empty())
        {
            if(freshoranges==0)
                return time;
            time++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(pair<int,int> d:dir)
                {
                    int x=p.first+d.first;
                    int y=p.second+d.second;
                    if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1)
                    {
                        freshoranges--;
                        q.push({x,y});
                        grid[x][y]=2;
                    }
                }
            }
        }
        return freshoranges>0 ? -1:0;
    }
};
