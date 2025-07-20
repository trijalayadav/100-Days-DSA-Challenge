class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        function<bool(int, int, int)> dfs = [&](int i, int j, int k)
        {
            if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k])
                return false;

            if (k == word.size() - 1)
                return true;

            char temp = board[i][j];
            board[i][j] = '#';

            bool found = dfs(i + 1, j, k + 1) ||
                         dfs(i - 1, j, k + 1) ||
                         dfs(i, j + 1, k + 1) ||
                         dfs(i, j - 1, k + 1);

            board[i][j] = temp;

            return found;
        };

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (dfs(i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
