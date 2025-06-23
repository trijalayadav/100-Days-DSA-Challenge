// User function Template for C++
#include <bits/stdc++.h>
class Solution
{
public:
    pair<int, int> getMinMax(vector<int> arr)
    {
        // code here
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            if (mini > arr[i])
            {
                mini = arr[i];
            }
            if (maxi < arr[i])
            {
                maxi = arr[i];
            }
        }
        pair<int, int> ans;
        ans.first = mini;
        ans.second = maxi;
        return ans;
    }
};