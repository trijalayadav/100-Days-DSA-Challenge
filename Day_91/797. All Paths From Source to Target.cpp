class Solution
{
public:
    void dfs(vector<vector<int>> &graph, int node, vector<int> &path,
             vector<vector<int>> &ans)
    {
        path.push_back(node);
        if (node == graph.size() - 1)
            ans.push_back(path);
        else
        {
            for (int next : graph[node])
            {
                dfs(graph, next, path, ans);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        // dfs
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph, 0, path, ans);
        return ans;

        // bfs
        // vector<vector<int>> ans;
        // queue<vector<int>> q;
        // q.push({0});

        // while (!q.empty()) {
        //     vector<int> path = q.front();
        //     q.pop();
        //     int last = path.back();
        //     if (last == graph.size() - 1) {
        //         ans.push_back(path);
        //     } else {
        //         for (int next : graph[last]) {
        //             vector<int> newPath = path;
        //             newPath.push_back(next);
        //             q.push(newPath);
        //         }
        //     }
        // }
        // return ans;
    }
};