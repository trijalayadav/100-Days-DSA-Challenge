class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group,
                          vector<int> &profit)
    {
        const int MOD = 1e9 + 7;
        int m = group.size();

        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;

        for (int idx = 0; idx < m; idx++)
        {
            int g = group[idx];
            int p = profit[idx];

            for (int j = n - g; j >= 0; j--)
            {
                for (int k = minProfit; k >= 0; k--)
                {
                    int newProfit = min(minProfit, k + p);
                    dp[j + g][newProfit] =
                        (dp[j + g][newProfit] + dp[j][k]) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int j = 0; j <= n; j++)
        {
            ans = (ans + dp[j][minProfit]) % MOD;
        }

        return ans;
    }
};