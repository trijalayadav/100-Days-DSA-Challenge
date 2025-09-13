class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        // brute force approach
        // int n = s.size(), ans = 0;
        // for (int i = 0; i < n; i++) {
        //     vector<int> freq(26, 0);
        //     for (int j = i; j < n; j++) {
        //         freq[s[j] - 'A']++;
        //         int maxFreq = *max_element(freq.begin(), freq.end());
        //         int len = j - i + 1;
        //         if (len - maxFreq <= k) {
        //             ans = max(ans, len);
        //         }
        //     }
        // }
        // return ans;

        // optimal - sliding window
        vector<int> freq(26, 0);
        int l = 0;
        int maxFreq = 0, ans = 0;
        for (int r = 0; r < s.size(); r++)
        {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};