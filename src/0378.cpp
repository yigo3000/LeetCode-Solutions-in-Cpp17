class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0];
        int r = matrix.back().back();
        while (l < r)
        {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (auto& x : matrix)
            {
                cnt += upper_bound(begin(x), end(x), m) - begin(x);
            }
            if (cnt < k)
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