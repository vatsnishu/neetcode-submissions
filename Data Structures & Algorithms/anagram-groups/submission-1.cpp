class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str:strs)
        {
            vector<int> count(26,0);
            for(char c:str)
                count[c-'a']++;
            string key;
            for(int i=0;i<26;i++)
            {
                key+=to_string(count[i])+"#";
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto p:mp)
        {
            res.push_back(p.second);
        }
        return res;
    }
};
