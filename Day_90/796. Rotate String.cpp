class Solution
{
public:
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

    // KMP Search
    bool KMPsearch(string &text, string &pattern)
    {
        int n = text.size(), m = pattern.size();
        vector<int> lps = buildLPS(pattern);

        int i = 0, j = 0; // i -> text index, j -> pattern index
        while (i < n)
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
                if (j == m)
                    return true; // full match
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1]; // fallback in pattern
                }
                else
                {
                    i++; // move text
                }
            }
        }
        return false;
    }
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;
        int n = s.length();
        //  for (int i = 0; i < n; i++) {
        //      // brute
        //      //  char first = s[0];
        //      //  s.erase(s.begin());
        //      //  s.push_back(first);
        //      //  if (s == goal)
        //      //      return true;

        //     // brute with string slicing
        //     // string rotated = s.substr(i) + s.substr(0, i);
        //     // if (rotated == goal)
        //     //     return true;
        // }
        // return false;

        // string concatination
        //  string doubled = s + s;
        //  return doubled.find(goal) != string::npos;

        // kmp algo
        if (s.size() != goal.size())
            return false;
        string doubled = s + s;
        return KMPsearch(doubled, goal);
    }
};