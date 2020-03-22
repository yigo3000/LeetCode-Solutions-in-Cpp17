class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, tmp, nums, 0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int n)
    {
        res.emplace_back(tmp);
        for (int i = n; i < size(nums); ++i)
        {
            tmp.emplace_back(nums[i]);
            dfs(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};