class Solution {
public:
    queue<pair<int,int>> fill(vector<vector<int>>& heights, vector<vector<bool>> &visited, string oceantype)
    {
        queue<pair<int,int>> q;
        if(oceantype=="atlantic")
        {
            for(int i=0;i<heights[0].size();i++)
            {
                q.push({heights.size()-1, i});
                visited[heights.size()-1][i]=true;
            }
            for(int i=0;i<heights.size()-1;i++)
            {
                q.push({i,heights[0].size()-1});
                visited[i][heights[0].size()-1]=true;
            }
        }
        else
        {
            for(int i=0;i<heights[0].size();i++)
            {
                q.push({0, i});
                visited[0][i]=true;
            }
            for(int i=1;i<heights.size();i++)
            {
                q.push({i,0});
                visited[i][0]=true;
            }
        }
        return q;
    }
    vector<vector<bool>> process(vector<vector<int>>& heights, string oceantype)
    {
        vector<pair<int,int>> dir={{-1,0}, {0,-1}, {1,0}, {0,1}};
        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
        queue<pair<int,int>> q=fill(heights, visited, oceantype);
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            for(pair<int,int> d:dir)
            {
                int x=p.first+d.first;
                int y=p.second+d.second;
                if(x>=0 && y>=0 && x<heights.size() && y<heights[0].size() && heights[x][y]>=heights[p.first][p.second] && !visited[x][y])
                {
                    q.push({x,y});
                    visited[x][y]=true;
                }
            }
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific=process(heights, "pacific");
        vector<vector<bool>> atlantic=process(heights, "atlantic");
        vector<vector<int>> res;
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
