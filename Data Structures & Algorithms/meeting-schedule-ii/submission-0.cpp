/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<vector<int>> vec;
        for(Interval interval:intervals)
        {
            vec.push_back({interval.start, 1});
            vec.push_back({interval.end, 0});
        }
        sort(vec.begin(), vec.end());
        int res=0;
        int rooms=0;
        for(vector<int> &v:vec)
        {
            if(v[1]==0)
            {
                rooms--;
            }
            else
            {
                rooms++;
                res=max(res, rooms);
            }
        }
        return res;
    }
};
