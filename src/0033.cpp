class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, size(nums), target);
    }
    
    int binarySearch(vector<int>& nums, int l, int r, int target)
    {
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[m] >= nums[l])
            {
                if (target >= nums[l] && target < nums[m])
                {
                    r = m;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                if (target > nums[m] && target <= nums[r - 1])
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
        }
        return -1;
    }
};