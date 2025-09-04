class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        else if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        else if (dividend == divisor)
        {
            return 1;
        }
        else if (divisor == 1)
        {
            return dividend;
        }
        bool sign = true; // positive
        if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = false;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        while (n >= d)
        {
            int cnt = 0;
            while (n >= (d << (cnt + 1)))
            {
                cnt++;
            }
            ans = ans + (1LL << cnt);
            n = n - (d << cnt);
        }
        if (sign)
        {
            return ans;
        }
        else
        {
            return -ans;
        }
    }
};