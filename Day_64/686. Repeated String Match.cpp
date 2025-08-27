// brute force approach
// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         int m = a.length(), n = b.length();
//         if (b == "") {
//             return 0;
//         }
//         string newA = a;
//         int count = 1;
//         //append a string until it's length is greater than length of b
//         while (newA.length() < n) {
//             newA = newA + a;
//             count++;
//         }
//         // check if b is substring of newA. if yes then return count otherwise append a. Repeat for two times
//         for (int i = 0; i < 2; i++) {
//             if (newA.find(b) != string::npos)
//                 return count;
//             else {
//                 newA += a;
//                 count++;
//             }
//         }
//         //if b is still not substring of newA then return -1
//         return -1;
//     }
// };

// optimal approach
class Solution
{
public:
    // Build LPS array for pattern (b)
    vector<int> buildLPS(string &pattern)
    {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0; // length of previous longest prefix suffix
        int i = 1;

        while (i < m)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1]; // fallback
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // KMP search: check if pattern exists in text
    bool KMPSearch(string &text, string &pattern)
    {
        int n = text.size(), m = pattern.size();
        vector<int> lps = buildLPS(pattern);
        int i = 0, j = 0; // i = index for text, j = index for pattern

        while (i < n)
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
                if (j == m)
                    return true; // full pattern matched
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b)
    {
        int m = a.size(), n = b.size();
        string repeated = a;
        int count = 1;

        // Repeat until length >= length of b
        while (repeated.size() < n)
        {
            repeated += a;
            count++;
        }

        // First check
        if (KMPSearch(repeated, b))
            return count;

        // One more repetition (handles overlap)
        repeated += a;
        count++;
        if (KMPSearch(repeated, b))
            return count;

        return -1;
    }
};

// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         int m = a.size(), n = b.size();

//         // Minimum number of repeats needed
//         int repeat = (n + m - 1) / m;  // ceil(n/m)

//         // Build repeated string and check
//         string repeated = "";
//         for (int i = 0; i < repeat; i++) repeated += a;
//         if (repeated.find(b) != string::npos) return repeat;

//         // Try one more repeat
//         repeated += a;
//         if (repeated.find(b) != string::npos) return repeat + 1;

//         // Try one more again (in rare overlap cases)
//         repeated += a;
//         if (repeated.find(b) != string::npos) return repeat + 2;

//         return -1;
//     }
// };
