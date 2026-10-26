class Solution {
public:
    void process(int n, int open, int close, vector<string> &res, vector<char> &vec)
    {
        if(open==close && open==n)
        {
            res.push_back(string(vec.begin(), vec.end()));
            return;
        }
        if(open<n)
        {
            vec.push_back('(');
            process(n,open+1, close, res, vec);
            vec.pop_back();
        }
        if(open> close)
        {
            vec.push_back(')');
            process(n,open, close+1, res, vec);
            vec.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> vec;
        process(n, 0, 0, res, vec);
        return res;
    }
};
