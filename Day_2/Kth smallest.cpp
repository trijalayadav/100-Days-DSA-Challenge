// User function template for C++
#include <bits/stdc++.h>
class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        // code here
        // sort(arr.begin(),arr.end());
        // return arr[k-1];

        priority_queue<int> pq;
        for (int i = 0; i < arr.size(); i++)
        {
            pq.push(arr[i]);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};