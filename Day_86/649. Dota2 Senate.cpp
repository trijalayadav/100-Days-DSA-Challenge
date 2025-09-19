class Solution
{
public:
    string predictPartyVictory(string senate)
    {

        // brute
        //  int n = senate.size();
        //  vector<bool> banned(n, false);

        // while (true) {
        //     bool radiantAlive = false, direAlive = false;
        //     for (int i = 0; i < n; i++) {
        //         if (banned[i])
        //             continue;
        //         char party = senate[i];
        //         if (party == 'R')
        //             radiantAlive = true;
        //         else
        //             direAlive = true;

        //         int j = (i + 1) % n;
        //         while (j != i) {
        //             if (!banned[j] && senate[j] != party) {
        //                 banned[j] = true;
        //                 break;
        //             }
        //             j = (j + 1) % n;
        //         }
        //     }
        //     if (!radiantAlive)
        //         return "Dire";
        //     if (!direAlive)
        //         return "Radiant";
        // }

        // optimal
        queue<int> radiant, dire;
        int n = senate.size();

        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        while (!radiant.empty() && !dire.empty())
        {
            int r = radiant.front();
            radiant.pop();
            int d = dire.front();
            dire.pop();

            if (r < d)
            {
                radiant.push(r + n);
            }
            else
            {
                dire.push(d + n);
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};