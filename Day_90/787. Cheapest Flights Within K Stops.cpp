class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k)
    {
        // Dijkstra
        // vector<vector<pair<int, int>>> graph(n);
        // for (auto& f : flights)
        //     graph[f[0]].push_back({f[1], f[2]});
        // using T = tuple<int, int, int>;
        // priority_queue<T, vector<T>, greater<T>> pq;
        // pq.push({0, src, 0});

        // vector<int> stops(n, INT_MAX);

        // while (!pq.empty()) {
        //     auto [cost, u, step] = pq.top();
        //     pq.pop();

        //     if (u == dst)
        //         return cost;
        //     if (step > k || step >= stops[u])
        //         continue;

        //     stops[u] = step;

        //     for (auto& [v, w] : graph[u]) {
        //         pq.push({cost + w, v, step + 1});
        //     }
        // }
        // return -1;

        // bellman
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        for (int i = 0; i <= k; i++)
        {
            vector<int> temp = dist;
            for (auto &f : flights)
            {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] != 1e9 && dist[u] + w < temp[v])
                {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};