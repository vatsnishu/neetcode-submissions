class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++)
        {
            gas[i]-=cost[i];
        }
        int totalfuel=0;
        int fuel=0;
        int ans=0;
        for(int i=0;i<gas.size();i++)
        {
            fuel+=gas[i];
            totalfuel+=gas[i];
            if(fuel<0)
            {
                fuel=0;
                ans=i+1;
            }
        }
        return totalfuel<0?-1:ans;
    }
};
