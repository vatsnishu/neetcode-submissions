class Solution {
public:
    int jump(vector<int>& nums) {
        int maxtillnow=0;
        int maxoverall=0;
        int jump=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>maxtillnow)
            {
                maxtillnow=maxoverall;
                jump++;
            }
            maxoverall=max(maxoverall, i+nums[i]);
        }
        return jump;
    }
};
