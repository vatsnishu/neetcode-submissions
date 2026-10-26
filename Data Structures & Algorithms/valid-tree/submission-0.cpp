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

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)
            return false;
        vector<int> p(n, -1);
        vector<int> rank(n, 0);
        for(vector<int> e:edges)
        {
            if(!union1(e[0], e[1], p, rank))   
                return false;
        }
        return true;
    }
};
