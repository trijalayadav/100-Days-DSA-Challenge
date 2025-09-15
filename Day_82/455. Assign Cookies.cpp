class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = 0, j = 0, m = g.size(), n = s.size();
        while (i < m && j < n)
        {
            if (s[j] >= g[i])
            {
                i++;
                j++;
                ans++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};