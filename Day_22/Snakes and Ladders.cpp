class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> flatten(n * n + 1, -1);

        int idx = 1;
        bool leftToRight = true;
        for (int row = n - 1; row >= 0; row--)
        {
            if (leftToRight)
            {
                for (int col = 0; col < n; col++)
                    flatten[idx++] = board[row][col];
            }
            else
            {
                for (int col = n - 1; col >= 0; col--)
                    flatten[idx++] = board[row][col];
            }
            leftToRight = !leftToRight;
        }

        queue<pair<int, int>> q;
        vector<bool> visited(n * n + 1, false);
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty())
        {
            auto [curr, moves] = q.front();
            q.pop();

            for (int i = 1; i <= 6; i++)
            {
                int next = curr + i;
                if (next > n * n)
                    break;

                if (flatten[next] != -1)
                    next = flatten[next];

                if (!visited[next])
                {
                    if (next == n * n)
                        return moves + 1;
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }
};
