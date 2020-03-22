class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (empty(nums)) return 0;
        int l = 0;
        int r = 1;
        while (r < size(nums))
        {
            if (nums[l] != nums[r]) nums[++l] = nums[r];
            ++r;
        }
        return l + 1;
    }
};