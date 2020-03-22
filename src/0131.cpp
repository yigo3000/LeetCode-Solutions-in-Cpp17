class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (empty(s)) return res;
        vector<string> tmp;
        dfs(res, tmp, s, 0);
        return res;
    }

    void dfs(vector<vector<string>>& res, vector<string>& tmp, string_view s, int n)
    {
        if (n == size(s))
        {
            res.emplace_back(tmp);
            return;
        }
        for (int i = n; i < size(s); ++i)
        {
            if (isValid(s, n, i))
            {
                tmp.emplace_back(s.substr(n, i - n + 1));
                dfs(res, tmp, s, i + 1);
                tmp.pop_back();
            }
        }
    }

    bool isValid(string_view s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};