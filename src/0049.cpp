class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        int idx = -1;
        for (auto& x : strs)
        {
            string tmp = x;
            sort(begin(tmp), end(tmp));
            if (!m.count(tmp))
            {
                res.emplace_back(vector<string>{x});
                m.emplace(tmp, ++idx);
            }
            else
            {
                res[m[tmp]].emplace_back(x);
            }
        }
        return res;
    }
};