class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // int ans = nums[0];
        // for (int i = 1; i < nums.size(); i++) {
        //     ans ^= nums[i];
        // }
        // return ans;

        int lo = 0, hi = nums.size() - 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (mid % 2 == 1)
                mid--; // to point mid at start of pair
            if (nums[mid] == nums[mid + 1])
            {
                lo = mid + 2;
            }
            else
            {
                hi = mid;
            }
        }
        return nums[lo];
    }
};