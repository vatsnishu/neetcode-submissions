class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> freq1;
        for(char c:s1)
        {
            freq1[c]++;
        }
        int found=0;
        unordered_map<char,int> freq2;
        int j=0;
        for(int i=0;i<s2.length();i++)
        {
            if(freq1.find(s2[i])!=freq1.end())
            {
                freq2[s2[i]]++;
                if(freq1[s2[i]]==freq2[s2[i]])
                    found++;
            }
            if(i>=s1.length() && freq1.find(s2[i-s1.length()])!=freq1.end())
            {
                if(freq1[s2[i-s1.length()]]==freq2[s2[i-s1.length()]])
                    found--;
                freq2[s2[i-s1.length()]]--;
            }
            if(found==freq1.size())
                return true;
        }
        return false;
    }
};
