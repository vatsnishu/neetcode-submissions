class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left=0;
        int res=0;
        int maxfreq=0;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]]=freq[s[i]]+1;
            maxfreq=max(maxfreq, freq[s[i]]);
            int window=i-left+1;
            if(window-maxfreq>k)
            {
                freq[s[left]]-=1;
                left=left+1;
            }
            res=max(res, i-left+1);
        }
        return res;
    }
};
