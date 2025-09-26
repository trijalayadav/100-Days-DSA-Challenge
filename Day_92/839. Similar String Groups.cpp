class Solution
{
public:
    // brute
    // bool isSimilar(string& a, string& b) {
    //     int diff = 0;
    //     for (int i = 0; i < a.size(); i++) {
    //         if (a[i] != b[i])
    //             diff++;
    //         if (diff > 2)
    //             return false;
    //     }
    //     return diff == 0 || diff == 2;
    // }
    // void dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
    //     vis[u] = 1;
    //     for (int v : adj[u]) {
    //         if (!vis[v])
    //             dfs(v, adj, vis);
    //     }
    // }
    // int numSimilarGroups(vector<string>& strs) {
    //     int n = strs.size();
    //     vector<vector<int>> adj(n);
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             if (isSimilar(strs[i], strs[j])) {
    //                 adj[i].push_back(j);
    //                 adj[j].push_back(i);
    //             }
    //         }
    //     }

    //     int groups = 0;
    //     vector<int> vis(n, 0);
    //     for (int i = 0; i < n; i++) {
    //         if (!vis[i]) {
    //             groups++;
    //             dfs(i, adj, vis);
    //         }
    //     }
    //     return groups;
    // }

    // union find
    struct DSU
    {
        vector<int> parent, rank;
        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x)
        {
            if (x != parent[x])
                parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int x, int y)
        {
            int rx = find(x), ry = find(y);
            if (rx == ry)
                return;
            if (rank[rx] < rank[ry])
                parent[rx] = ry;
            else if (rank[ry] < rank[rx])
                parent[ry] = rx;
            else
            {
                parent[ry] = rx;
                rank[rx]++;
            }
        }
    };
    bool isSimilar(string &a, string &b)
    {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                diff++;
            if (diff > 2)
                return false;
        }
        return diff == 0 || diff == 2;
    }
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        DSU dsu(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isSimilar(strs[i], strs[j]))
                {
                    dsu.unite(i, j);
                }
            }
        }

        int groups = 0;
        for (int i = 0; i < n; i++)
        {
            if (dsu.find(i) == i)
                groups++;
        }
        return groups;
    }
};