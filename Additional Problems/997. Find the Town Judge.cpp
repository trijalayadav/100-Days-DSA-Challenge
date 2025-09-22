class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        // brute
        // for (int i = 1; i <= n; i++) {
        //     bool trustsNobody = true;
        //     bool trustedByAll = true;

        //     for (auto& t : trust) {
        //         if (t[0] == i)
        //             trustsNobody = false;
        //         if (t[1] == i)
        //             continue;
        //     }

        //     for (int j = 1; j <= n; j++) {
        //         if (j == i)
        //             continue;
        //         bool found = false;
        //         for (auto& t : trust) {
        //             if (t[0] == j && t[1] == i) {
        //                 found = true;
        //                 break;
        //             }
        //         }
        //         if (!found) {
        //             trustedByAll = false;
        //             break;
        //         }
        //     }

        //     if (trustsNobody && trustedByAll)
        //         return i;
        // }
        // return -1;

        // better
        // vector<int> indegree(n + 1, 0), outdegree(n + 1, 0);
        // for (auto& t : trust) {
        //     outdegree[t[0]]++;
        //     indegree[t[1]]++;
        // }
        // for (int i = 1; i <= n; i++) {
        //     if (indegree[i] == n - 1 && outdegree[i] == 0) {
        //         return i;
        //     }
        // }
        // return -1;

        // optimal
        vector<int> score(n + 1, 0);
        for (auto &t : trust)
        {
            score[t[0]]--;
            score[t[1]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (score[i] == n - 1)
                return i;
        }
        return -1;
    }
};