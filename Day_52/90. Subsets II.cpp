class Solution
{
public:
    void solve(int index, vector<int> &nums, vector<int> &subset,
               vector<vector<int>> &result)
    {
        result.push_back(subset);
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            subset.push_back(nums[i]);
            solve(i + 1, nums, subset, result);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        solve(0, nums, subset, result);
        return result;
    }
};