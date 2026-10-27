class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
        int maxtillnow=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            maxsum=max(nums[i]+maxsum, nums[i]);
            maxtillnow=max(maxsum, maxtillnow);
        }
        return maxtillnow;
    }
};
