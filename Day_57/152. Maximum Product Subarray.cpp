class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = INT_MIN;
        for (int i : nums)
        {
            res = max(res, i);
        }
        int curMin = 1, curMax = 1;
        for (int n : nums)
        {
            if (n == 0)
            {
                curMin = 0, curMax = 0;
                continue;
            }
            int temp = curMax;
            curMax = max({n, n * curMax, n * curMin});
            curMin = min({n, n * temp, n * curMin});
            res = max(res, curMax);
        }
        return res;
    }
};