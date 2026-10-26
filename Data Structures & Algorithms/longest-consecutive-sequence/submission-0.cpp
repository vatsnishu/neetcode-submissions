class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num:nums)
        {
            st.insert(num);
        }
        int res=0;
        for(int num:st)
        {
            if(st.find(num-1)==st.end())
            {
                int count=0;
                while(st.find(num)!=st.end())
                {
                    num++;
                    count++;
                }
                res=max(res, count);
            }
        }
        return res;
    }
};
