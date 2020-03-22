class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i < size(nums); ++i)
        {
            if (i > mx) return false;
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
};