class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
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
        return dp[sz];
    }
};