class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &ans,
             vector<vector<int>> &image, int &color, vector<int> &delRow,
             vector<int> &delCol, int &iniColor)
    {
        ans[row][col] = color;
        int n = ans.size();
        int m = ans[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if ((nRow < n && nCol < m) && (nRow >= 0 && nCol >= 0))
            {
                if (image[nRow][nCol] == iniColor && ans[nRow][nCol] != color)
                {
                    dfs(nRow, nCol, ans, image, color, delRow, delCol,
                        iniColor);
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, color, delRow, delCol, iniColor);
        return ans;
    }
};