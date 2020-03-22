class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int sz = size(nums);
        if (sz < 3) return res;
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = sz - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] + nums[i] < 0)
                {
                    ++l;
                }
                else if (nums[l] + nums[r] + nums[i] > 0)
                {
                    --r;
                }
                else
                {
                    res.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    ++l;
                    --r;
                }
            }
        }
        return res;
    }
};