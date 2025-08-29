class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // heap
        //  vector<int> ans;
        //  unordered_map<int, int> freq;
        //  for (int num : nums) {
        //      freq[num]++;
        //  }
        //  priority_queue<pair<int, int>, vector<pair<int, int>>,
        //                 greater<pair<int, int>>>
        //      minHeap;

        // for (auto& p : freq) {
        //     minHeap.push({p.second, p.first});
        //     if (minHeap.size() > k) {
        //         minHeap.pop();
        //     }
        // }

        // while (!minHeap.empty()) {
        //     ans.push_back(minHeap.top().second);
        //     minHeap.pop();
        // }

        // return ans;

        // bucket sort
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto &p : freq)
        {
            bucket[p.second].push_back(p.first);
        }

        vector<int> ans;
        for (int i = n; i >= 0 && ans.size() < k; i--)
        {
            for (int num : bucket[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};