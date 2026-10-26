class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordmap(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length()+1, false);
        dp[0]=true;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(dp[j] && wordmap.find(s.substr(j, i-j+1))!=wordmap.end())
                {
                    dp[i+1]=true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
