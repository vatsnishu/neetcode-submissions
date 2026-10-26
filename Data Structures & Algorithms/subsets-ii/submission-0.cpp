class Solution {
public:
    void process(vector<int> &nums, vector<vector<int>> &res, vector<int> &vec, int index)
    {
        res.push_back(vec);
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index && nums[i-1]==nums[i])
                continue;
            vec.push_back(nums[i]);
            process(nums, res, vec, i+1);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> vec;
        process(nums, res, vec, 0);
        return res;
    }
};
