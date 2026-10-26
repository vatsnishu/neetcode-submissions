class Solution {
public:

    int delimeter=256;
    string encode(vector<string>& strs) {
        string res;
        for (const string& str : strs) {
            res += to_string(str.length()) + "#" + str;
        }
        return res;
    }
    
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.length()) {
            int hash_pos = s.find('#', i);
            int len = stoi(s.substr(i, hash_pos - i));
            res.push_back(s.substr(hash_pos + 1, len));
            i = hash_pos + 1 + len;
        }
        return res;
    }
};
