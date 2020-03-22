/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        deque<TreeNode*> d{root};
        bool flag = true;
        while (!empty(d))
        {
            vector<int> tmp;
            int n = size(d);
            while (n--)
            {
                if (flag)
                {
                    TreeNode* t = d.back();
                    tmp.emplace_back(t->val);
                    d.pop_back();
                    if (t->left) d.emplace_front(t->left);
                    if (t->right) d.emplace_front(t->right);
                }
                else
                {
                    TreeNode* t = d.front();
                    tmp.emplace_back(t->val);
                    d.pop_front();
                    if (t->right) d.emplace_back(t->right);
                    if (t->left) d.emplace_back(t->left);
                }
            }
            flag = !flag;
            res.emplace_back(tmp);
        }
        return res;
    }
};