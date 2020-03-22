class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = size(nums);
        int res = INT_MIN;
        int sum = 0;
        for (auto& x : nums)
        {
            if (sum >= 0)
            {
                sum += x;
            }
            else
            {
                sum = x;
            }
            res = max(res, sum);
        }
        return res;
    }
};