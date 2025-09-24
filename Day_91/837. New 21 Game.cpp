class Solution
{
public:
    // brute
    double brute(int n, int k, int maxPts, int cur)
    {
        if (cur >= k)
            return (cur <= n) ? 1.0 : 0.0;
        double p = 0.0;
        for (int draw = 1; draw <= maxPts; ++draw)
        {
            p += brute(n, k, maxPts, cur + draw);
        }
        return p / maxPts;
    }
    // better
    double dfs(int n, int k, int maxPts, int cur, vector<double> &memo)
    {
        if (cur >= k)
            return (cur <= n) ? 1.0 : 0.0;
        if (memo[cur] >= -0.5)
            return memo[cur];

        double p = 0.0;
        for (int draw = 1; draw <= maxPts; ++draw)
        {
            p += dfs(n, k, maxPts, cur + draw, memo);
        }
        memo[cur] = p / maxPts;
        return memo[cur];
    }
    double new21Game(int n, int k, int maxPts)
    {
        // return brute(n, k, maxPts, 0);
        if (k == 0)
            return 1.0;
        if (n >= k + maxPts)
            return 1.0;

        int size = k + maxPts;
        vector<double> dp(size, 0.0);
        for (int s = k; s <= n && s < size; ++s)
            dp[s] = 1.0;
        double window = 0.0;
        for (int j = 0; j < maxPts; ++j)
        {
            int idx = k + j;
            if (idx < size)
                window += dp[idx];
        }
        for (int i = k - 1; i >= 0; --i)
        {
            dp[i] = window / maxPts;
            window += dp[i];
            window -= dp[i + maxPts];
        }

        return dp[0];
    }
};