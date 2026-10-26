class Solution {
public:
    pair<int,int> expand(string &s, int left, int right)
    {
        while(left>=0 && right<s.length() && s[left]==s[right])
        {
            left--;
            right++;
        }
        left++;
        right--;
        return {left, right-left+1};
    }
    string longestPalindrome(string s) {
        int reslen=0;
        int resstart=-1;
        for(int i=0;i<s.length();i++)
        {
            pair<int,int> even=expand(s, i, i);
            pair<int,int> odd=expand(s, i, i+1);

            if(reslen<even.second)
            {
                resstart=even.first;
                reslen=even.second;
            }
            if(reslen<odd.second)
            {
                resstart=odd.first;
                reslen=odd.second;
            }
        }
        return s.substr(resstart, reslen);
    }
};
