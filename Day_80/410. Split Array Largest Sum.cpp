// brute force- recursive
// class Solution {
// public:
//     int solve(vector<int>& nums, int k, int idx) {
//         if (k == 1) {
//             return accumulate(nums.begin() + idx, nums.end(), 0);
//         }
//         int n = nums.size();
//         int sum = 0, ans = INT_MAX;

//         for (int i = idx; i < n - k + 1; i++) {
//             sum += nums[i];
//             int next = solve(nums, k - 1, i + 1);
//             ans = min(ans, max(sum, next));
//         }
//         return ans;
//     }
//     int splitArray(vector<int>& nums, int k) { return solve(nums, k, 0); }
// };

// dp approach
// class Solution {
// public:
//     int splitArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<long long> prefix(n + 1, 0);
//         for (int i = 0; i < n; i++) {
//             prefix[i + 1] = prefix[i] + nums[i];
//         }
//         vector<vector<long long>> dp(n + 1,
//                                      vector<long long>(k + 1, LLONG_MAX));
//         dp[0][0] = 0;
//         for (int i = 1; i <= n; i++) {
//             for (int K = 1; K <= k; K++) {
//                 for (int j = 0; j < i; j++) {
//                     long long sum = prefix[i] - prefix[j];
//                     dp[i][K] = min(dp[i][K], max(dp[j][K - 1], sum));
//                 }
//             }
//         }
//         return (int)dp[n][k];
//     }
// };

// binary search + greedy
class Solution
{
public:
    bool canSplit(vector<int> &nums, int k, long long mid)
    {
        long long sum = 0;
        int count = 1;
        for (int num : nums)
        {
            if (sum + num > mid)
            {
                count++;
                sum = num;
                if (count > k)
                    return false;
            }
            else
            {
                sum += num;
            }
        }
        return true;
    }
    int splitArray(vector<int> &nums, int k)
    {
        long long left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0LL);

        while (left < right)
        {
            long long mid = (left + right) / 2;
            if (canSplit(nums, k, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};