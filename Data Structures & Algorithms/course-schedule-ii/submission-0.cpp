class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> res;
        for(vector<int> pre:prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            res.push_back(x);
            for(int y:adj[x])
            {
                indegree[y]--;
                if(indegree[y]==0)
                {
                    q.push(y);
                }
            }
        }
        return res.size()==numCourses?res:vector<int>();
    }
};
