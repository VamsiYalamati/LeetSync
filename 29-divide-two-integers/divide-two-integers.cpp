class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long first
        long long a = dividend;
        long long b = divisor;

        // Determine sign
        bool negative = (a < 0) ^ (b < 0);

        a = abs(a);
        b = abs(b);

        long long ans = 0;

        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Keep doubling while possible
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            ans += multiple;
        }

        if (negative)
            ans = -ans;

        return (int)ans;
    }
};