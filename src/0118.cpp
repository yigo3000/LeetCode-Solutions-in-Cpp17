class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        if (numRows == 0) return dp;
        dp.emplace_back(vector<int>{1});
        if (numRows == 1) return dp;
        dp.emplace_back(vector<int>{1, 1});
        if (numRows == 2) return dp;

        for (int i = 2; i < numRows; ++i)
        {
            vector<int> tmp(i + 1);
            tmp.back() = 1;
            tmp.front() = 1;
            for (int j = 1; j < size(tmp) - 1; ++j)
            {
                tmp[j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            dp.emplace_back(tmp);
        }
        return dp;
    }
};