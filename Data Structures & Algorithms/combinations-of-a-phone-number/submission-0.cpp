class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return {};
        unordered_map<char, string> mp={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> res={""};
        for(char d:digits)
        {
            vector<string> vec;
            for(char c:mp[d])
            {
                for(string str:res)
                {
                    vec.push_back(str+c);
                }
            }
            res=vec;
        }
        return res;
    }
};
