class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int maxCount = 0;
        // for(int i=0;i<n;i++){
        //     int count=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]==1) count++;
        //         else break;
        //         maxCount=max(maxCount,count);
        //     }
        // }
        // return maxCount;
        // the above aproach gives time limit exceeded

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};