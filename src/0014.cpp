class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (empty(strs)) return "";
        string s = strs[0];
        for (auto& x : strs)
        {
            if (x == strs[0]) continue;
            if (empty(s)) return "";
            int i = 0;
            while (s[i] == x[i])
            {
                ++i;
                if (i == size(s) || i == size(x)) break;
            }
            s = s.substr(0, i);
        }
        return s;
    }
};