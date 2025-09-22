class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        // recursive
        // if (n == 1)
        //     return 0;
        // int parent = kthGrammar(n - 1, (k + 1) / 2);
        // if (k % 2 == 1)
        //     return parent;
        // else
        //     return 1 - parent;

        // iterative
        int res = 0;
        while (n > 1)
        {
            if (k % 2 == 0)
                res ^= 1;
            k = (k + 1) / 2;
            --n;
        }
        return res;
    }
};