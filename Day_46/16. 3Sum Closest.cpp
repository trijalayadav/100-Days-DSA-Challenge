class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (abs(currentSum - target) < abs(closestSum - target))
                {
                    closestSum = currentSum;
                }

                if (currentSum == target)
                {
                    return target;
                }
                else if (currentSum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return closestSum;
    }
};
