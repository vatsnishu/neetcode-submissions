class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        while(i<nums.size()-2)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                    while(j<k && nums[j-1]==nums[j])
                        j++;
                }
                else if(sum>0)
                {
                    k--;
                    while(j<k && nums[k+1]==nums[k])
                        k--;
                }
                else
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j<k && nums[j-1]==nums[j])
                        j++;
                    k--;
                    while(j<k && nums[k+1]==nums[k])
                        k--;
                }
            }
            i++;
            while(i<nums.size()-2 && nums[i-1]==nums[i])
            {
                i++;
            }
        }
        return res;
    }
};
