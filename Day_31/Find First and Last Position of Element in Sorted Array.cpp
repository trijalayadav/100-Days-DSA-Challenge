class Solution
{
public:
    int findFirst(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, first = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return first;
    }

    int findLast(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, last = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                last = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};
