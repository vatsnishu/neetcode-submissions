class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        while(1)
        {
            slow=nums[slow];
            fast=nums[fast];
            fast=nums[fast];
            if(slow==fast)
                break;
        }
        fast=0;
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
