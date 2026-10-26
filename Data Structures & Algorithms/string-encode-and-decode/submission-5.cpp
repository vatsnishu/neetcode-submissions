class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (const string& str : strs) {
            res += to_string(str.length()) + "#" + str;
        }
        return res;
    }
    
    vector<string> decode(string s) {
        vector<string> res;
        int start=0;
        while(start<s.length())
        {
            int end=s.find("#", start);
            int length=stoi(s.substr(start, end-start));
            res.push_back(s.substr(end+1,length));
            start=end+length+1;
        }
        return res;
    }
};
