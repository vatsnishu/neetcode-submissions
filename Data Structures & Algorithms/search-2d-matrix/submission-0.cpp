class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int r=matrix.size()*matrix[0].size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int row=m/matrix[0].size();
            int col=m%matrix[0].size();
            if(matrix[row][col]==target)
            {
                return true;
            }
            if(matrix[row][col]<target)
                l=m+1;
            else
                r=m-1;
        }
        return false;
    }
};
