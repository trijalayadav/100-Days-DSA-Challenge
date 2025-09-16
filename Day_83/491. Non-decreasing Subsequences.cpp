// brute force
// class Solution {
// public:
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>> uniqueRes;

//         for (int mask = 0; mask < (1 << n); mask++) {
//             vector<int> subseq;
//             for (int i = 0; i < n; i++) {
//                 if (mask & (1 << i))
//                     subseq.push_back(nums[i]);
//             }
//             if (subseq.size() >= 2) {
//                 bool ok = true;
//                 for (int i = 1; i < subseq.size(); i++) {
//                     if (subseq[i] < subseq[i - 1]) {
//                         ok = false;
//                         break;
//                     }
//                 }
//                 if (ok)
//                     uniqueRes.insert(subseq);
//             }
//         }
//         return vector<vector<int>>(uniqueRes.begin(), uniqueRes.end());
//     }
// };

// better-backtracking
// class Solution {
// public:
//     set<vector<int>> uniqueRes;
//     vector<int> path;

//     void dfs(vector<int>& nums, int start) {
//         if (path.size() >= 2)
//             uniqueRes.insert(path);

//         for (int i = start; i < nums.size(); i++) {
//             if (!path.empty() && nums[i] < path.back())
//                 continue;

//             path.push_back(nums[i]);
//             dfs(nums, i + 1);
//             path.pop_back();
//         }
//     }

//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         dfs(nums, 0);
//         return vector<vector<int>>(uniqueRes.begin(), uniqueRes.end());
//     }
// };

// optimal
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &nums, int start)
    {
        if (path.size() >= 2)
            res.push_back(path);

        unordered_set<int> used; // to skip duplicates at this recursion depth
        for (int i = start; i < nums.size(); i++)
        {
            if (!path.empty() && nums[i] < path.back())
                continue;
            if (used.count(nums[i]))
                continue;
            used.insert(nums[i]);

            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }
};
