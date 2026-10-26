class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res={intervals[0]};
        for(vector<int> interval:intervals)
        {
            if(res.back()[1]<interval[0])
            {
                res.push_back(interval);
            }
            else if(res.back()[0]>interval[1])
            {
                res.push_back(interval);
                swap(res[res.size()-1], res[res.size()-2]);
            }
            else
            {
                res[res.size()-1][0]=min(res.back()[0], interval[0]);
                res[res.size()-1][1]=max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};
