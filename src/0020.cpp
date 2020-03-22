class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        for (auto& x : s)
        {
            if (x == '(' || x == '[' || x == '{') v.emplace(x);
            else if (x == ')')
            {
                if (empty(v) || v.top() != '(') return false;
                v.pop();
            }
            else if (x == ']')
            {
                if (empty(v) || v.top() != '[') return false;
                v.pop();
            }
            else if (x == '}')
            {
                if (empty(v) || v.top() != '{') return false;
                v.pop();
            }
        }
        return empty(v);
    }
};