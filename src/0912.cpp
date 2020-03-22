class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, size(nums) - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int n = partition(nums, l, r);
        quickSort(nums, l, n - 1);
        quickSort(nums, n + 1, r);
    }

    int partition(vector<int>& nums, int l, int r)
    {
        int i = l;
        int j = r;
        while (i < j)
        {
            while (i < j && nums[j] >= nums[l]) --j;
            while (i < j && nums[i] <= nums[l]) ++i;
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[l]);
        return i;
    }
};