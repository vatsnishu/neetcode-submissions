class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int start=0;
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                start=max(start, mp[s[i]]+1);
            }
            res=max(res, i-start+1);
            mp[s[i]]=i;
        }
        return res;
    }
};
