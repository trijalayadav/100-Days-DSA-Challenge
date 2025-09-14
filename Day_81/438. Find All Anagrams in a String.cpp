// O(n*m)
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int n = s.length(), m = p.length();
//         if (n < m)
//             return {};

//         vector<int> pmap(26, 0);
//         for (char ch : p) {
//             pmap[ch - 'a']++;
//         }

//         vector<int> ans;
//         for (int i = 0; i <= n - m; i++) {
//             string temp = s.substr(i, m);
//             vector<int> smap(26, 0);
//             for (char ch : temp) {
//                 smap[ch - 'a']++;
//             }
//             if (smap == pmap) {
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };

// O(n)
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int n = s.size(), m = p.size();
//         if (n < m)
//             return {};

//         vector<int> pmap(26, 0), smap(26, 0);
//         vector<int> ans;

//         for (char ch : p)
//             pmap[ch - 'a']++;

//         for (int i = 0; i < m; i++)
//             smap[s[i] - 'a']++;
//         if (smap == pmap)
//             ans.push_back(0);

//         for (int i = m; i < n; i++) {
//             smap[s[i] - 'a']++;
//             smap[s[i - m] - 'a']--;
//             if (smap == pmap)
//                 ans.push_back(i - m + 1);
//         }
//         return ans;
//     }
// };

// matchCount trick

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size(), m = p.size();
        if (n < m)
            return {};

        vector<int> pmap(26, 0), smap(26, 0);
        for (char ch : p)
            pmap[ch - 'a']++;

        vector<int> ans;
        int matchCount = 0;

        for (int i = 0; i < m; i++)
            smap[s[i] - 'a']++;

        for (int i = 0; i < 26; i++)
        {
            if (smap[i] == pmap[i])
                matchCount++;
        }

        if (matchCount == 26)
            ans.push_back(0);

        for (int i = m; i < n; i++)
        {
            int add = s[i] - 'a';
            int remove = s[i - m] - 'a';

            smap[add]++;
            if (smap[add] == pmap[add])
                matchCount++;
            else if (smap[add] - 1 == pmap[add])
                matchCount--;

            smap[remove]--;
            if (smap[remove] == pmap[remove])
                matchCount++;
            else if (smap[remove] + 1 == pmap[remove])
                matchCount--;

            if (matchCount == 26)
                ans.push_back(i - m + 1);
        }
        return ans;
    }
};