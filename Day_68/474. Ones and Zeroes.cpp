class Solution {
public:
    int solve(int idx, vector<string>& strs, int m, int n) {
        if (idx == strs.size()) return 0;  // no strings left

        // count zeros and ones in current string
        int zeros = 0, ones = 0;
        for (char c : strs[idx]) {
            if (c == '0') zeros++;
            else ones++;
        }

        // choice 1: skip
        int notTake = solve(idx+1, strs, m, n);

        // choice 2: take (if possible)
        int take = 0;
        if (m >= zeros && n >= ones) {
            take = 1 + solve(idx+1, strs, m-zeros, n-ones);
        }

        return max(take, notTake);
    }

    int solveMem(int idx, vector<string>& strs, int m, int n, vector<vector<vector<int>>>& dp) {
        if (idx == strs.size()) return 0;
        if (dp[idx][m][n] != -1) return dp[idx][m][n];

        int zeros = 0, ones = 0;
        for (char c : strs[idx]) {
            if (c == '0') zeros++;
            else ones++;
        }

        int notTake = solveMem(idx+1, strs, m, n, dp);
        int take = 0;
        if (m >= zeros && n >= ones) {
            take = 1 + solveMem(idx+1, strs, m-zeros, n-ones, dp);
        }

        return dp[idx][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // return solve(0, strs, m, n);

        // int L = strs.size();
        // vector<vector<vector<int>>> dp(L, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        // return solveMem(0, strs, m, n, dp);

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (string &s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }
            
            // Update in reverse to prevent reusing same string
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]);
                }
            }
        }

        return dp[m][n];
    }
};