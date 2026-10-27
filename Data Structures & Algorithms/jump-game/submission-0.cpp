class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxtillnow=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>maxtillnow)
                return false;
            maxtillnow=max(maxtillnow, i+nums[i]);
        }
        return true;
    }
};
