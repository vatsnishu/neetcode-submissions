class Solution {
public:
    int process(vector<int> nums, int left, int right)
    {
        int x1=nums[left];
        int x2=max(nums[left+1], nums[left]);
        for(int i=left+2;i<=right;i++)
        {
            int x3=max(x2, x1+nums[i]);
            x1=x2;
            x2=x3;
        }
        return max(x1, x2);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0], nums[1]);      
        return max(process(nums, 0, nums.size()-2), process(nums, 1, nums.size()-1));
    }
};
