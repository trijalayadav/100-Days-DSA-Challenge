// brute force approach
// class Solution {
// public:
//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<vector<int>> ans;
//         vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//         int total = 1 << 9;

//         for (int mask = 0; mask < total; mask++) {
//             vector<int> subset;
//             int sum = 0;

//             for (int i = 0; i < 9; i++) {
//                 if (mask & (1 << i)) {
//                     subset.push_back(nums[i]);
//                     sum += nums[i];
//                 }
//             }

//             if (subset.size() == k && sum == n) {
//                 ans.push_back(subset);
//             }
//         }
//         return ans;
//     }
// };

// better
//  class Solution {
//  public:
//      vector<vector<int>> ans;
//      vector<int> path;

//     void backtrack(int start, int k, int n) {
//         if (path.size() == k) {
//             if (n == 0) ans.push_back(path);
//             return;
//         }

//         for (int i = start; i <= 9; i++) {
//             path.push_back(i);
//             backtrack(i + 1, k, n - i);
//             path.pop_back();
//         }
//     }

//     vector<vector<int>> combinationSum3(int k, int n) {
//         backtrack(1, k, n);
//         return ans;
//     }
// };

// optimal
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(int start, int k, int n)
    {
        if (k == 0 && n == 0)
        {
            ans.push_back(path);
            return;
        }
        if (k == 0 || n <= 0)
            return;

        for (int i = start; i <= 9; i++)
        {
            if (i > n)
                break;
            path.push_back(i);
            backtrack(i + 1, k - 1, n - i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtrack(1, k, n);
        return ans;
    }
};
