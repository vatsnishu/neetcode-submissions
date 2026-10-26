class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int minprice=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            res=max(res, prices[i]-minprice);
            minprice=min(minprice, prices[i]);
        }
        return res;
    }
};
