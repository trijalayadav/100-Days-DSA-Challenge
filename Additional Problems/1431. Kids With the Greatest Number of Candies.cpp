class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxi = INT_MIN;
        for (int i : candies)
        {
            maxi = max(maxi, i);
        }
        int n = candies.size();
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++)
        {
            if (candies[i] + extraCandies >= maxi)
            {
                ans[i] = true;
            }
        }
        return ans;
    }
};