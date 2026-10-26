class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> matchingopen={{')', '('}, {']', '['}, {'}', '{'}};
        for(char c:s)
        {
            if(matchingopen.find(c)==matchingopen.end())
            {
                st.push(c);
            }
            else if(st.empty())
            {
                return false;
            }
            else if(matchingopen[c]!=st.top())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        return st.empty();
    }
};
