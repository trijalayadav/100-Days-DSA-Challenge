class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return 0;
        }
        int n = x;
        long long rev = 0;
        while (n != 0)
        {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n = n / 10;
        }
        return rev == x;
    }
};