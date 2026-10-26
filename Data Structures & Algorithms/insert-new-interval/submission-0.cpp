class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res={newInterval};
        sort(intervals.begin(), intervals.end());
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
