class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int flip0 = 0, flip1 = 0;

        for (char c : s)
        {
            int newFlip0 = flip0, newFlip1 = 0;

            if (c == '0')
            {
                newFlip1 = min(flip0, flip1) + 1;
            }
            else
            {
                newFlip0 = flip0 + 1;
                newFlip1 = min(flip0, flip1);
            }

            flip0 = newFlip0;
            flip1 = newFlip1;
        }

        return min(flip0, flip1);
    }
};