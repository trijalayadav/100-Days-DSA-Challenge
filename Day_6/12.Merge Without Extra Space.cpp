class Solution
{
public:
    int kthSmallest(vector<int> &a, vector<int> &b, int k)
    {
        int n = a.size(), m = b.size();
        int lo = 0, hi = n, idx = 0;
        while (lo <= hi)
        {
            int mid1 = (lo + hi) / 2;
            int mid2 = k - mid1;
            if (mid2 > m)
            {
                lo = mid1 + 1;
                continue;
            }

            int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
            int r1 = (mid1 == n ? INT_MAX : a[mid1]);
            int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
            int r2 = (mid2 == m ? INT_MAX : b[mid2]);

            if (l1 <= r2 && l2 <= r1)
            {
                idx = mid1;
                break;
            }
            if (l1 > r2)
                hi = mid1 - 1;
            else
                lo = mid1 + 1;
        }
        return idx;
    }
    void mergeArrays(vector<int> &a, vector<int> &b)
    {
        // code here
        // for (int i = b.size() - 1; i >= 0; i--) {
        //     if (a.back() > b[i]) {
        //         int last = a.back();
        //         int j = a.size() - 2;
        //         while (j >= 0 && a[j] > b[i]) {
        //             a[j + 1] = a[j];
        //             j--;
        //         }
        //         a[j + 1] = b[i];
        //         b[i] = last;
        //     }
        // }//tle

        // int n = a.size();
        // int m = b.size();
        // int idx = kthSmallest(a, b, n);

        // for (int i = idx; i < n; i++) {
        //     swap(a[i], b[i - idx]);
        // }
        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());

        // int i = a.size() - 1, j = 0;
        // while (i >= 0 && j < b.size() && a[i] > b[j]) {
        //     swap(a[i--], b[j++]);
        // }

        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());

        int n = a.size();
        int m = b.size();
        int gap = (n + m + 1) / 2;
        while (gap > 0)
        {
            int i = 0, j = gap;
            while (j < n + m)
            {
                if (j < n && a[i] > a[j])
                {
                    swap(a[i], a[j]);
                }
                else if (i < n && j >= n && a[i] > b[j - n])
                {
                    swap(a[i], b[j - n]);
                }
                else if (i >= n && b[i - n] > b[j - n])
                {
                    swap(b[i - n], b[j - n]);
                }
                i++;
                j++;
            }
            if (gap == 1)
                break;
            gap = (gap + 1) / 2;
        }
    }
};