class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqt;
        for(char c:t)
            freqt[c]++;
        unordered_map<char,int> freqs;
        int j=0;
        int resstart=-1;
        int reslen=INT_MAX;
        int found=0;
        for(int i=0;i<s.length();i++)
        {
            if(freqt.find(s[i])!=freqt.end())
            {
                freqs[s[i]]++;
                if(freqs[s[i]]==freqt[s[i]])
                    found++;
            }
            while(found==freqt.size())
            {
                if(reslen>i-j+1)
                {
                    resstart=j;
                    reslen=i-j+1;
                }
                if(freqt.find(s[j])!=freqt.end())
                {
                    if(freqs[s[j]]==freqt[s[j]])
                        found--;              
                    freqs[s[j]]--;
                }
                j++;
            }
        }
        return reslen!=INT_MAX?s.substr(resstart, reslen):"";
    }
};
