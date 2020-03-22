class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }

    void dfs(vector<string>& res, string s, int l, int r)
    {
        if (l == 0 && r == 0)
        {
            res.emplace_back(s);
            return;
        }
        if (l <= r)
        {
            if (l > 0) dfs(res, s + '(', l - 1, r);
            if (r > 0) dfs(res, s + ')', l, r - 1);
        }
    }
};