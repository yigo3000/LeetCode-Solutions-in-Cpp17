class Solution {
public:
    int myAtoi(string str) {
        int n = 0;
        while (str[n] == ' ')
        {
            ++n;
            if (n == size(str)) return 0;
        }
        if (isalpha(str[n])) return 0;
        int flag = 1;
        if (str[n] == '+')
        {
            ++n;
        }
        else if (str[n] == '-')
        {
            flag = -1;
            ++n;
        }
        long res = 0;
        while (isdigit(str[n]))
        {
            res = res * 10 + (str[n] - '0');
            if (res > INT_MAX) return (flag > 0) ? INT_MAX : INT_MIN;
            ++n;
        }
        return res * flag;
    }
};