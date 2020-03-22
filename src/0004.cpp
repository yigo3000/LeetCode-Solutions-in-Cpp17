class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = size(nums1) + size(nums2);
        int x = (n + 1) / 2;
        int y = (n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, x) + findKth(nums1, 0, nums2, 0, y)) / 2.0;
    }
    
    double findKth(vector<int>& nums1, int a, vector<int>& nums2, int b, int k)
    {
        int sz1 = size(nums1);
        int sz2 = size(nums2);
        if (a >= sz1) return nums2[b + k - 1];
        if (b >= sz2) return nums1[a + k - 1];
        if (k == 1) return min(nums1[a], nums2[b]);
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        if (a + k / 2 - 1 < sz1) m1 = nums1[a + k / 2 - 1];
        if (b + k / 2 - 1 < sz2) m2 = nums2[b + k / 2 - 1];
        if (m1 < m2) return findKth(nums1, a + k / 2, nums2, b, k - k / 2);
        return findKth(nums1, a, nums2, b + k / 2, k - k / 2);
    }
};