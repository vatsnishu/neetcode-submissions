class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> inc;
        for(int num:nums)
        {
            int l=0;
            int r=inc.size()-1;
            int ans=inc.size();
            while(l<=r)
            {
                int m=l+(r-l)/2;
                if(inc[m]>=num)
                {
                    ans=m;
                    r=m-1;
                }
                else
                {
                    l=m+1;
                }
            }
            if(ans==inc.size())
            {
                inc.push_back(num);
            }
            else
            {
                inc[ans]=num;
            }
        }
        return inc.size();
    }
};
