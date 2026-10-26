class Solution {
public:
    int climbStairs(int n) {
        int x=0;
        int y=1;
        for(int i=0;i<n;i++)
        {
            int z=x+y;
            x=y;
            y=z;
        }
        return y;
    }
};
