class Solution
{
public:
    bool solve(int index, vector<int> &arr, int N, int target)
    {
        if (index >= N)
        {
            return 0;
        }
        if (target < 0)
        {
            return 0;
        }
        if (target == 0)
        {
            return 1;
        }
        int incl = solve(index + 1, arr, N, target - arr[index]);
        int excl = solve(index + 1, arr, N, target - 0);

        return incl or excl;
    }
    bool solveMem(int index, vector<int> &arr, int N, int target,
                  vector<vector<int>> &dp)
    {
        if (index >= N)
        {
            return 0;
        }
        if (target < 0)
        {
            return 0;
        }
        if (target == 0)
        {
            return 1;
        }
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        int incl = solveMem(index + 1, arr, N, target - arr[index], dp);
        int excl = solveMem(index + 1, arr, N, target, dp);

        return dp[index][target] = incl or excl;
    }
    bool solveTab(vector<int> &arr, int N, int target)
    {
        vector<vector<int>> dp(N + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = 0; j <= target; j++)
            {
                int incl = 0;
                if (j - arr[i] >= 0)
                {
                    incl = dp[i + 1][j - arr[i]];
                }
                int excl = dp[i + 1][j];
                dp[i][j] = incl or excl;
            }
        }
        return dp[0][target];
    }
    bool solveTab2(vector<int> &arr, int N, int target)
    {
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);
        curr[0] = 1;
        next[0] = 1;
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = 0; j <= target; j++)
            {
                int incl = 0;
                if (j - arr[i] >= 0)
                {
                    incl = next[j - arr[i]];
                }
                int excl = next[j];
                curr[j] = incl or excl;
            }
            next = curr;
        }
        return curr[target];
    }
    bool canPartition(vector<int> &nums)
    {
        // code here
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        int N = nums.size();
        // return solve(0,nums,N,target);

        // vector<vector<int>> dp(N,vector<int>(target+1,-1));
        // return solveMem(0,nums,N,target,dp);

        // return solveTab(nums,N,target);

        return solveTab2(nums, N, target);
    }
};