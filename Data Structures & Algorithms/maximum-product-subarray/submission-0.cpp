class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int prevmaxi=maxi;
            int prevmini=mini;
            if(nums[i]<0)
            {
                mini=min(prevmaxi*nums[i], nums[i]);
                maxi=max(prevmini*nums[i], nums[i]);
            }
            else
            {
                mini=min(prevmini*nums[i], nums[i]);
                maxi=max(prevmaxi*nums[i], nums[i]);
            }
            res=max(maxi, res);
        }
        return res;
    }
};
