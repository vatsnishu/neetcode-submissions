class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        while(l<r)
        {
            if(!isalnum(s[l]))
            {
                l++;
                continue;
            }
            if(!isalnum(s[r]))
            {
                r--;
                continue;
            }
            if(isupper(s[l]))
            {
                s[l]=s[l]-'A'+'a';
            }
            if(isupper(s[r]))
            {
                s[r]=s[r]-'A'+'a';
            }
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
