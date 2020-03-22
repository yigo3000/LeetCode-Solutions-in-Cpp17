class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (empty(grid) || empty(grid[0])) return 0;
        int m = size(grid);
        int n = size(grid[0]);
        vector<int> p(m * n);
        iota(begin(p), end(p), 0);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int t = i * n + j;
                if (i + 1 < m && grid[i][j] == grid[i + 1][j]) join(p, t, t + n);
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) join(p, t, t + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < size(p); ++i)
        {
            if (p[i] == i && grid[i / n][i % n] == '1') ++res;
        }
        return res;
    }

    int find(vector<int>& p, int i)
    {
        while (p[i] != i) i = p[i];
        return i;
    }

    void join(vector<int>& p, int a, int b)
    {
        p[find(p, b)] = p[find(p, a)];
    }
};