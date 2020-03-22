class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int l = 0;
        int r = 0;
        for (auto& x : s)
        {
            if (x == '(')
            {
                ++l;
            }
            else if (x == ')')
            {
                if (l > 0)
                {
                    --l;
                }
                else
                {
                    ++r;
                }
            }
        }
        dfs(res, s, 0, l, r);
        return res;
    }
    
    void dfs(vector<string>& res, string_view s, int n, int l, int r)
    {
        if (!l && !r)
        {
            if (isValid(s)) res.emplace_back(s);
            return;
        }
        for (int i = n; i < size(s); ++i)
        {
            if (i > n && s[i] == s[i - 1]) continue;
            if (l && s[i] == '(')
            {
                dfs(res, string{s.substr(0, i)} + string{s.substr(i + 1)}, i, l - 1, r);
            }
            else if (r && s[i] == ')')
            {
                dfs(res, string{s.substr(0, i)} + string{s.substr(i + 1)}, i, l, r - 1);
            }
        }
    }
    
    bool isValid(string_view s)
    {
        int cnt = 0;
        for (auto& x : s)
        {
            if (x == '(')
            {
                ++cnt;
            }
            else if (x == ')')
            {
                --cnt;
            }
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
};