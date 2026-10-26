class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> vec;
        for(int i=0;i<position.size();i++)
        {
            vec.push_back({position[i], (float)(target-position[i])/(float)(speed[i])});
        }
        sort(vec.begin(), vec.end());
        int res=position.size();
        for(int i=vec.size()-1;i>0;i--)
        {
            if(vec[i].second>=vec[i-1].second)
            {
                vec[i-1].second=vec[i].second;
                res--;
            }
        }
        return res;
    }
};
