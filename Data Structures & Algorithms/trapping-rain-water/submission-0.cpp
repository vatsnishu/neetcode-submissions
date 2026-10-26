class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.begin(), height.end());
        vector<int> right(height.begin(), height.end());
        for(int i=1;i<height.size();i++)
        {
            left[i]=max(left[i-1], height[i]);
        }
        for(int i=height.size()-2;i>=0;i--)
        {
            right[i]=max(right[i+1], height[i]);
        }
        int res=0;
        for(int i=0;i<height.size();i++)
        {
            res+=min(left[i], right[i])-height[i];
        }
        return res;
    }
};
