class Solution
{
public:
    int countOdds(int low, int high)
    {
        // O(n)
        // int odds = 0;
        // for (int i = low; i <= high; i++) {
        //     if (i % 2 != 0) {
        //         odds++;
        //     }
        // }
        // return odds;

        // O(1)
        int total = high - low + 1;
        return total / 2 + (low % 2 != 0 && high % 2 != 0 ? 1 : 0);
    }
};