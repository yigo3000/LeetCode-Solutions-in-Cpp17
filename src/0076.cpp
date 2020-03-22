class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (auto& x : t) ++m[x];

        int sz = size(s);
        int minLen = INT_MAX;
        int start = 0;

        int l = 0;
        int r = 0;
        int cnt = 0;

        while (r < sz)
        {
            if (--m[s[r]] >= 0) ++cnt;
            ++r;
            while (cnt == size(t))
            {
                if (r - l < minLen)
                {
                    minLen = r - l;
                    start = l;
                }
                if (++m[s[l]] > 0) --cnt;
                ++l;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};