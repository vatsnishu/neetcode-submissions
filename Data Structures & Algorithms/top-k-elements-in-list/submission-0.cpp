class Solution {
public:
    struct comp
    {
        bool operator()(const pair<int,int> &x, const pair<int,int> &y)
        {
            return x.second>y.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num:nums)
        {
            freq[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        for(auto p:freq)
        {
            pq.push(p);
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
