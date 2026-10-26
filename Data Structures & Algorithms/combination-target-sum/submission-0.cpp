class Solution {
public:
    void process(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &vec, int index)
    {
        if(target==0)
        {
            res.push_back(vec);
            return;
        }
        if(target<0 || index==candidates.size())
        {
            return;
        }
        process(candidates, target, res, vec, index+1);
        vec.push_back(candidates[index]);
        process(candidates, target-candidates[index], res, vec, index);
        vec.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> vec;
        process(nums, target, res, vec, 0);
        return res;
    }
};
