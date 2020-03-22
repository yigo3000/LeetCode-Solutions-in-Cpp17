class Solution {
public:
    int strStr(string haystack, string needle) {
        if (empty(needle)) return 0;
        int m = size(haystack);
        int n = size(needle);
        for (int i = 0; i < m; ++i)
        {
            if (m - i < n) break;
            if (haystack[i] == needle[0])
            {
                int j = 0;
                while (haystack[i + j] == needle[j])
                {
                    ++j;
                    if (j == n) return i;
                }
            }
        }
        return -1;
    }
};