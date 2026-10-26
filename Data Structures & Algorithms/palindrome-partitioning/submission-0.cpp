class Solution {
public:
    void find(string &s, vector<vector<bool>> &ispalindrome, int index, vector<string> &vec, vector<vector<string>> &res)
    {
        if(index==s.length())
        {
            res.push_back(vec);
            return;
        }
        string str;
        for(int i=index;i<s.length();i++)
        {
            str+=s[i];
            if(ispalindrome[index][i])
            {
                vec.push_back(str);
                find(s, ispalindrome, i+1, vec, res);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> ispalindrome(s.length(), vector<bool>(s.length(), false));
        for(int l=1;l<=s.length();l++)
        {
            for(int i=0;i<s.length()-l+1;i++)
            {
                int j=i+l-1;
                if(s[i]==s[j])
                    ispalindrome[i][j]=l<=2?true:ispalindrome[i+1][j-1];
            }
        }

        vector<vector<string>> res;
        vector<string> vec;
        find(s, ispalindrome, 0, vec, res);
        return res;
    }
};
