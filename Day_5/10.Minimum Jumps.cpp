class Solution
{
public:
    int solve(vector<int> &nums, int index)
    {
        if (index >= nums.size() - 1)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= nums[index]; i++)
        {
            if (index + i < nums.size())
            {
                int count = solve(nums, index + i);
                if (count != INT_MAX)
                {
                    ans = min(1 + count, ans);
                }
            }
        }
        return ans;
    }
    int solveMem(vector<int> &nums, int index, vector<int> &dp)
    {
        if (index >= nums.size() - 1)
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= nums[index]; i++)
        {
            if (index + i < nums.size())
            {
                int count = solveMem(nums, index + i, dp);
                if (count != INT_MAX)
                {
                    ans = min(1 + count, ans);
                }
            }
        }
        dp[index] = ans;
        return dp[index];
    }
    int solveTab(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        for (int index = n - 2; index >= 0; index--)
        {
            for (int i = 1; i <= nums[index]; i++)
            {
                if (index + i < n && dp[index + i] != INT_MAX)
                {
                    int count = dp[index + i];
                    dp[index] = min(1 + count, dp[index]);
                }
            }
        }
        return dp[0] == INT_MAX ? -1 : dp[0];
    }
    int minJumps(vector<int> &arr)
    {
        // code here
        // return solve(arr, 0);

        // vector<int> dp(arr.size(), -1);
        // return solveMem(arr, 0, dp);

        return solveTab(arr);
    }
};