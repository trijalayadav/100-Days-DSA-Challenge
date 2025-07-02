class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int n = arr.size();
        int maxProd = arr[0];
        int currMax = arr[0];
        int currMin = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0)
                swap(currMax, currMin);

            currMax = max(arr[i], currMax * arr[i]);
            currMin = min(arr[i], currMin * arr[i]);

            maxProd = max(maxProd, currMax);
        }

        return maxProd;
    }
};
