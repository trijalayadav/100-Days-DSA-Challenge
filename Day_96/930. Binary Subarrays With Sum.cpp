class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int curr = 0, count = 0;
        for (int x : nums)
        {
            curr += x;
            if (freq.find(curr - goal) != freq.end())
                count += freq[curr - goal];
            freq[curr]++;
        }
        return count;
    }
};