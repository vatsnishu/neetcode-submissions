class Solution {
public:
    int expand(string &s, int left, int right)
    {
        int res=0;
        while(left>=0 && right<s.length() && s[left]==s[right])
        {
            left--;
            right++;
            res++;
        }
        left++;
        right--;
        return res;
    }
        
    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            res+=expand(s, i, i);
            res+=expand(s, i, i+1);
        }
        return res;
    }
};
