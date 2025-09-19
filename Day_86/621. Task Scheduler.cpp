class Solution
{
public:
    // brute
    int solve(vector<int> &freq, int n, int time, vector<int> &nextAvail,
              int tasksLeft)
    {
        if (tasksLeft == 0)
        {
            return time;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0 && nextAvail[i] <= time)
            {
                freq[i]--;
                int prev = nextAvail[i];
                nextAvail[i] = time + n + 1;
                ans = min(ans,
                          solve(freq, n, time + 1, nextAvail, tasksLeft - 1));
                freq[i]++;
                nextAvail[i] = prev;
            }
        }
        if (ans == INT_MAX)
        {
            ans = solve(freq, n, time + 1, nextAvail, tasksLeft);
        }
        return ans;
    }
    int leastInterval(vector<char> &tasks, int n)
    {
        // vector<int> freq(26, 0);
        // for (char ch : tasks) {
        //     freq[ch - 'A']++;
        // }
        // vector<int> nextAvail(26, 0);
        // return solve(freq, n, 0, nextAvail, tasks.size());

        // better
        //  vector<int> cnt(26, 0);
        //  for (char c : tasks)
        //      cnt[c - 'A']++;

        // priority_queue<int> pq;
        // for (int c : cnt)
        //     if (c)
        //         pq.push(c);

        // queue<pair<int, int>> wait;
        // int time = 0;

        // while (!pq.empty() || !wait.empty()) {
        //     time++;

        //     if (!pq.empty()) {
        //         int cur = pq.top();
        //         pq.pop();
        //         cur--;
        //         if (cur > 0)
        //             wait.push({time + n, cur});
        //     }

        //     if (!wait.empty() && wait.front().first == time) {
        //         pq.push(wait.front().second);
        //         wait.pop();
        //     }

        //     if (pq.empty() && !wait.empty()) {
        //         time = wait.front().first - 1;
        //     }
        // }
        // return time;

        // optimal
        vector<int> cnt(26, 0);
        for (char c : tasks)
            cnt[c - 'A']++;

        int f_max = *max_element(cnt.begin(), cnt.end());
        int count_max = count(cnt.begin(), cnt.end(), f_max);

        int part_count = f_max - 1;
        int part_length = n + 1;
        int min_len = part_count * part_length + count_max;

        return max((int)tasks.size(), min_len);
    }
};