class Solution {
public:
    void process(vector<int> &nums, vector<vector<int>> &res, int index, vector<int> &vec)
    {
        if(index==nums.size())
        {
            res.push_back(vec);
            return;
        }
        process(nums, res, index+1, vec);
        vec.push_back(nums[index]);
        process(nums, res, index+1, vec);
        vec.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        process(nums, res, 0, vec);
        return res;
    }
};
