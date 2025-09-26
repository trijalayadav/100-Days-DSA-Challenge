class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        // brute force
        // int n = hand.size();
        // if (n % groupSize != 0)
        //     return false;

        // multiset<int> ms(hand.begin(), hand.end());

        // while (!ms.empty()) {
        //     int start = *ms.begin();
        //     for (int i = 0; i < groupSize; i++) {
        //         auto it = ms.find(start + i);
        //         if (it == ms.end())
        //             return false;
        //         ms.erase(it);
        //     }
        // }
        // return true;

        // better
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> freq;
        for (int card : hand)
            freq[card]++;

        for (auto &[card, count] : freq)
        {
            if (count > 0)
            {
                for (int i = 1; i < groupSize; i++)
                {
                    int nextCard = card + i;
                    if (freq[nextCard] < count)
                        return false;
                    freq[nextCard] -= count;
                }
            }
        }
        return true;
    }
};