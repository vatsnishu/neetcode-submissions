class Solution {
public:
    int find(int x, vector<int> &p)
    {
        if(p[x]==-1)
            return x;
        return find(p[x], p);
    }

    bool union1(int x, int y, vector<int> &p, vector<int> &rank)
    {
        int px=find(x, p);
        int py=find(y, p);

        if(px==py)
            return false;
        if(rank[px]>rank[py])
        {
            p[py]=px;
        }
        else if(rank[py]>rank[px])
        {
            p[px]=py;
        }
        else
        {
            p[px]=py;
            rank[py]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(edges.size(), -1);
        vector<int> rank(edges.size(), 0);

        for(vector<int> e:edges)
        {
            if(!union1(e[0]-1, e[1]-1, p, rank))
                return e;
        }
        return {-1,-1};
    }
};
