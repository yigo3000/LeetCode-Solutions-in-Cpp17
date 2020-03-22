class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto& x : board)
        {
            unordered_map<char, int> m;
            for (auto& y : x)
            {
                if (y != '.') 
                {
                    if (m.count(y)) return false;
                    ++m[y];
                }
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            unordered_map<char, int> m;
            for (int j = 0; j < 9; ++j)
            {
                char tmp = board[j][i];
                if (tmp != '.')
                {
                    if (m.count(tmp)) return false;
                    ++m[tmp];
                }
            }
        }

        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                unordered_map<char, int> m;
                for (int k = 0; k < 3; ++k)
                {
                    for (int n = 0; n < 3; ++n)
                    {
                        char tmp = board[i + k][j + n];
                        if (tmp != '.')
                        {
                            if (m.count(tmp)) return false;
                            ++m[tmp];
                        }
                    }
                }
            }
        }

        return true;
    }
};