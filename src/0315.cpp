class Solution {
public:
    struct Node {
        int val;
        int cnt;
        int equal;
        Node* left;
        Node* right;
        Node(int v) : val(v), cnt(0), equal(1), left(nullptr), right(nullptr) {}
    };

    vector<int> countSmaller(vector<int> &nums) {
        if (empty(nums)) return vector<int>{};
        Node* root = new Node(nums.back());
        vector<int> res(size(nums));
        for (int i = size(nums) - 2; i >= 0; --i)
        {
            res[i] = insert(root, nums[i]);
        }
        deleteNode(root);
        return res;
    }

private:
    int insert(Node* node, int val)
    {
        if (val < node->val)
        {
            ++node->cnt;
            if (!node->left)
            {
                node->left = new Node(val);
                return 0;
            }
            else
            {
                return insert(node->left, val);
            }
        }
        else if (val > node->val)
        {
            if (!node->right)
            {
                node->right = new Node(val);
                return node->cnt + node->equal;
            }
            else
            {
                return node->cnt + node->equal + insert(node->right, val);
            }
        }
        else
        {
            ++node->equal;
            return node->cnt;
        }
    }

    void deleteNode(Node* node)
    {
        while (!node)
        {
            deleteNode(node->left);
            deleteNode(node->right);
            delete node;
        }
    }
};