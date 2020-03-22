class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < size(nums); ++i)
        {
            int x = target - nums[i];
            if (m.count(x))
            {
                return vector<int>{i, m[x]};
            }
            m.emplace(nums[i], i);
        }
        return vector<int>{-1, -1};
    }
};