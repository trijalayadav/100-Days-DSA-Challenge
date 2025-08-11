class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0)
            return 0;

        int minutes = -1;
        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};

        while (!q.empty())
        {
            int size = q.size();
            minutes++;
            for (int k = 0; k < size; k++)
            {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dirX[d];
                    int ny = y + dirY[d];

                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        freshCount--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return (freshCount == 0) ? minutes : -1;
    }
};