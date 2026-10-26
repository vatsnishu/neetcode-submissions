class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res=0;
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int x=st.top();
                st.pop();
                if(st.empty())
                {
                    res=max(res, heights[x]*(i));
                }
                else
                {
                    res=max(res, heights[x]*(i-st.top()-1));
                }
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int x=st.top();
            st.pop();
            if(st.empty())
            {
                res=max(res, heights[x]*(int)heights.size());
            }
            else
            {
                res=max(res, heights[x]*((int)heights.size()-st.top()-1));
            }
        }
        return res;
    }
};
