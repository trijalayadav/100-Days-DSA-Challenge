class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;
        int left = 1, right = x / 2;
        int ans = 0;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;
            if (sq == x)
            {
                return mid;
            }
            else if (sq < x)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};