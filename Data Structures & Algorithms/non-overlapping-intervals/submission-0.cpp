class Solution {
public:
    static bool cmp(vector<int> &x, vector<int> &y)
    {
        if(x[1]==y[1])
            return x[0]<y[0];
        return x[1]<y[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int res=0;
        int j=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[j][1]>intervals[i][0])
            {
                res++;
            }
            else
            {
                j=i;
            }
        }
        return res;
    }
};
