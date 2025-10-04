class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int x, int y, int empty, int &paths)
    {
        int rows = grid.size(), cols = grid[0].size();
        if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == -1)
            return;
        if (grid[x][y] == 2)
        {
            if (empty == -1)
                paths++;
            return;
        }
        grid[x][y] = -1;
        dfs(grid, x + 1, y, empty - 1, paths);
        dfs(grid, x - 1, y, empty - 1, paths);
        dfs(grid, x, y + 1, empty - 1, paths);
        dfs(grid, x, y - 1, empty - 1, paths);
        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int startX, startY, empty = 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 0)
                    empty++;
                else if (grid[i][j] == 1)
                {
                    startX = i;
                    startY = j;
                }
            }
        }
        int totalPaths = 0;
        dfs(grid, startX, startY, empty, totalPaths);
        return totalPaths;
    }
};