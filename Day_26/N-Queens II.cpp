class Solution
{
public:
    int totalNQueens(int n)
    {
        vector<bool> columns(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        return solve(0, n, columns, diag1, diag2);
    }

private:
    int solve(int row, int n, vector<bool> &columns, vector<bool> &diag1, vector<bool> &diag2)
    {
        if (row == n)
            return 1;
        int count = 0;
        for (int col = 0; col < n; ++col)
        {
            if (columns[col] || diag1[row - col + n - 1] || diag2[row + col])
                continue;

            columns[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

            count += solve(row + 1, n, columns, diag1, diag2);

            columns[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
        return count;
    }
};
