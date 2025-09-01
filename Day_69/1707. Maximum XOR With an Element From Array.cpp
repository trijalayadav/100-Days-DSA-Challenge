class Solution
{
public:
    struct TrieNode
    {
        TrieNode *child[2] = {nullptr, nullptr};
    };

    void insert(TrieNode *root, int num)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int query(TrieNode *root, int num)
    {
        TrieNode *node = root;
        int res = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->child[1 - bit])
            {
                res |= (1 << i);
                node = node->child[1 - bit];
            }
            else
            {
                node = node->child[bit];
            }
        }
        return res;
    }

    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(), nums.end());

        vector<int> res(queries.size());
        vector<array<int, 3>> qs;

        for (int i = 0; i < queries.size(); i++)
        {
            qs.push_back({queries[i][0], queries[i][1], i});
        }
        sort(qs.begin(), qs.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });

        TrieNode *root = new TrieNode();
        int j = 0;
        for (auto &q : qs)
        {
            int x = q[0], m = q[1], idx = q[2];

            while (j < nums.size() && nums[j] <= m)
            {
                insert(root, nums[j]);
                j++;
            }

            if (j == 0)
                res[idx] = -1;
            else
                res[idx] = query(root, x);
        }

        return res;
    }
};
