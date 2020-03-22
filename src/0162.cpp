class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = size(nums);
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (m + 1 < size(nums) && nums[m] < nums[m + 1])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};