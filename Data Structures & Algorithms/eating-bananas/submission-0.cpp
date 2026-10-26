class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(), piles.end());
        long long int res=INT_MAX;
        while(l<=r)
        {
            long long int m=l+(r-l)/2;
            long long int daystoeat=0;
            for(long long int pile:piles)
            {
                daystoeat+=(pile-1)/m+1;
            }
            if(daystoeat<=h)
            {
                res=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return res;
    }
};
