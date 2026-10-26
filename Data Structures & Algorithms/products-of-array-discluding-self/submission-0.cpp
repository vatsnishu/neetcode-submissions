class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        int prod=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            left[i]=prod;
            prod*=nums[i];
        }
        prod=nums.back();
        for(int i=nums.size()-2;i>=0;i--)
        {
            right[i]=prod;
            prod*=nums[i];
        }
        vector<int> res(nums.size(), 1);
        for(int i=0;i<nums.size();i++)
        {
            res[i]=left[i]*right[i];
        }
        return res;
    }
};
