class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        unordered_map<int, int> dp;
        dp[0] = 0;

        for (int r : rods)
        {
            auto cur = dp;
            for (auto [diff, height] : cur)
            {
                dp[diff + r] = max(dp[diff + r], height);
                int newDiff = abs(diff - r);
                int newHeight = height + min(diff, r);
                dp[newDiff] = max(dp[newDiff], newHeight);
            }
        }
        return dp[0];
    }
};