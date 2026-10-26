class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        int first=0;
        int second=1;
        for(int i=1;i<s.length();i++)
        {
            int third=s[i]!='0'?second:0;
            string str=s.substr(i-1, 2);
            if(stoi(str)>=10 && stoi(str)<=26)
            {
                third+=i>=2?first:1;
            }
            first=second;
            second=third;
        }
        return second;
    }
};
