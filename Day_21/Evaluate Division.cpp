class Solution
{
public:
    // Graph: variable -> list of (neighbor, weight)
    unordered_map<string, vector<pair<string, double>>> graph;

    bool dfs(string current, string target, unordered_set<string> &visited,
             double &result, double temp)
    {
        if (current == target)
        {
            result = temp;
            return true;
        }

        visited.insert(current);

        for (auto &neighbor : graph[current])
        {
            if (!visited.count(neighbor.first))
            {
                if (dfs(neighbor.first, target, visited, result,
                        temp * neighbor.second))
                {
                    return true;
                }
            }
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries)
    {
        // Step 1: Build the graph
        for (int i = 0; i < equations.size(); ++i)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].emplace_back(b, val);
            graph[b].emplace_back(a, 1.0 / val);
        }

        vector<double> results;

        // Step 2: Answer the queries
        for (auto &query : queries)
        {
            string src = query[0];
            string dst = query[1];

            if (!graph.count(src) || !graph.count(dst))
            {
                results.push_back(-1.0);
            }
            else if (src == dst)
            {
                results.push_back(1.0);
            }
            else
            {
                unordered_set<string> visited;
                double result = -1.0;
                dfs(src, dst, visited, result, 1.0);
                results.push_back(result);
            }
        }

        return results;
    }
};
