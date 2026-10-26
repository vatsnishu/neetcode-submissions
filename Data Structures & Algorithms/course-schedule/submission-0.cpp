class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(vector<int> pre:prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int done=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            done++;
            for(int y:adj[x])
            {
                indegree[y]--;
                if(indegree[y]==0)
                {
                    q.push(y);
                }
            }
        }
        return done==numCourses;
    }
};
