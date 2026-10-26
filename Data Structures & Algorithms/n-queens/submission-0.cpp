class Solution {
public:
    int cols;
    int diags;
    int antidiags;

    void process(vector<string> &vec, vector<vector<string>> &res, int row)
    {
        if(row==vec.size())
        {
            res.push_back(vec);
            return;
        }
        for(int col=0;col<vec.size();col++)
        {
            if(cols&(1<<col) || diags&(1<<(row+col)) || antidiags&(1<<(vec.size()+row-col)))
                continue;
            vec[row][col]='Q';
            cols|=(1<<col);
            diags|=(1<<(row+col));
            antidiags |= (1<<(vec.size()+row-col));
            process(vec, res, row+1);
            cols &= ~(1 << col);
            diags &= ~(1<<(row+col));
            antidiags &= ~(1<<(vec.size()+row-col));
            vec[row][col]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> vec(n, string(n, '.'));
        process(vec, res, 0);
        return res;
    }
};
