class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long x = labs(dividend);
        long y = labs(divisor);
        long res = 0;
        while (x >= y)
        {
            long tmp = y;
            long cnt = 1;
            while (x >= tmp + tmp)
            {
                tmp <<= 1;
                cnt <<= 1;
            }
            res += cnt;
            x -= tmp;
        }
        return (dividend ^ divisor) < 0 ? -res : res;
    }
};