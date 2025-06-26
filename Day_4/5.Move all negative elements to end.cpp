class Solution
{
public:
    int maxSubarraySum(vector<int> &arr)
    {
        // Your code here
        int sum = 0, maxSum = INT_MIN;
        for (int num : arr)
        {
            sum = sum + num;
            if (sum > maxSum)
            {
                maxSum = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
};