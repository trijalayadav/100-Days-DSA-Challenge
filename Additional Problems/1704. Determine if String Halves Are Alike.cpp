class Solution
{
public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s)
    {
        int n = s.length();
        string s1 = s.substr(0, n / 2);
        string s2 = s.substr(n / 2);
        int v1 = 0, v2 = 0;
        for (char ch : s1)
        {
            if (isVowel(ch))
            {
                v1++;
            }
        }
        for (char ch : s2)
        {
            if (isVowel(ch))
            {
                v2++;
            }
        }
        if (v1 == v2)
        {
            return true;
        }
        return false;
    }
};