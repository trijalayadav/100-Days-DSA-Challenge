class Solution
{
public:
    int longestConsecutive(vector<int> &arr)
    {
        unordered_set<int> s(arr.begin(), arr.end());
        int longest = 0;

        for (int num : arr)
        {
            // Only start counting if it's the beginning of a sequence
            if (s.find(num - 1) == s.end())
            {
                int currentNum = num;
                int currentStreak = 1;

                while (s.find(currentNum + 1) != s.end())
                {
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};
