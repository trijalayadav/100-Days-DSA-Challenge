class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1;
        int mid = 0;
        while (start < end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] > nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return nums[start];
    }
};