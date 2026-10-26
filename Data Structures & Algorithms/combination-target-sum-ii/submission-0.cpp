class Solution {
public:
    void process(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &vec, int index)
    {
        if(target==0)
        {
            res.push_back(vec);
            return;
        }
        if(target<0)
        {
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(i!=index && candidates[i-1]==candidates[i])
            {
                continue;
            }
            vec.push_back(candidates[i]);
            process(candidates, target-candidates[i], res, vec, i+1);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> vec;
        process(candidates, target, res, vec, 0);
        return res;
    }
};
