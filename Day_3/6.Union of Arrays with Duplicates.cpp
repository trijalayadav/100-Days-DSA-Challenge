#include <bits/stdc++.h>
class Solution
{
public:
    int findUnion(vector<int> &a, vector<int> &b)
    {
        // code here
        set<int> st;
        int i = 0;
        int j = 0;
        int m = a.size(), n = b.size();
        while (i < m)
        {
            st.insert(a[i]);
            i++;
        }
        while (j < n)
        {
            st.insert(b[j]);
            j++;
        }
        return st.size();
    }
};