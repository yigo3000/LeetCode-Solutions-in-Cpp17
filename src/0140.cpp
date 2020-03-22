class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(begin(wordDict), end(wordDict));
        int sz = size(s);
        vector<bool> dp(sz + 1);
        dp[0] = true;
        for (int i = 1; i <= sz; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && wordSet.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        vector<string> res;
        if (!dp[sz]) return res;
        vector<string> path;
        dfs(wordSet, dp, res, path, s, 0);
        return res; 
    }

    void dfs(unordered_set<string>& wordSet, vector<bool>& dp, vector<string>& res, vector<string>& path, string_view s, int n)
    {
        if (!dp[n]) return;
        if (n == size(s))
        {
            string tmp;
            for (int i = 0; i < size(path) - 1; ++i)
            {
                tmp += (path[i] + " ");
            }
            tmp += path.back();
            res.emplace_back(tmp);
        }
        for (int i = n; i < size(s); ++i)
        {
            string tmp{s.substr(n, i - n + 1)};
            if (wordSet.count(tmp))
            {
                path.emplace_back(tmp);
                dfs(wordSet, dp, res, path, s, i + 1);
                path.pop_back();
            }
        }
    }
};