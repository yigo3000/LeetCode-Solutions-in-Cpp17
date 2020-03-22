class Solution {
public:
    int rob(vector<int>& nums) {
        if (empty(nums)) return 0;
        vector<int> dp(size(nums) + 1);
        dp[1] = nums[0];
        for (int i = 1; i < size(nums); ++i)
        {
            dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
        }
        return dp[size(nums)];
    }
};