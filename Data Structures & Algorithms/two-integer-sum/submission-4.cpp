class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++)
        {
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        int l=0;
        int r=nums.size()-1;
        while(l<r)
        {
            int sum=vec[l].first+vec[r].first;
            if(sum==target)
                if(vec[l].second<vec[r].second)
                    return {vec[l].second,vec[r].second};
                else
                    return {vec[r].second,vec[l].second};
            if(sum<target)
                l++;
            else
                r--;
        }
        return {-1,-1};
    }
};
