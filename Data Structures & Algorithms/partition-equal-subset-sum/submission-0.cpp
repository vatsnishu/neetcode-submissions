class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0)
            return false;
        sum/=2;
        vector<int> dp(sum+1, false);
        dp[0]=true;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=sum;j>=nums[i];j--)
            {
                dp[j]=dp[j-nums[i]] | dp[j];
            }
        }
        return dp.back();
    }
};
