class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i : nums)
        {
            if (freq[i] > 0)
            {
                return i;
            }
            freq[i]++;
        }
        return 0;
    }
};