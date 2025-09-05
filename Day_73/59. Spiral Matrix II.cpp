class Solution
{
public:
    void fillSpiral(vector<vector<int>> &matrix, int top, int bottom, int left,
                    int right, int &num)
    {
        if (top > bottom || left > right)
            return;

        // left -> right
        for (int j = left; j <= right; j++)
            matrix[top][j] = num++;

        // top -> bottom
        for (int i = top + 1; i <= bottom; i++)
            matrix[i][right] = num++;

        // right -> left
        if (top < bottom)
        {
            for (int j = right - 1; j >= left; j--)
                matrix[bottom][j] = num++;
        }

        // bottom -> top
        if (left < right)
        {
            for (int i = bottom - 1; i > top; i--)
                matrix[i][left] = num++;
        }

        fillSpiral(matrix, top + 1, bottom - 1, left + 1, right - 1, num);
    }
    vector<vector<int>> generateMatrix(int n)
    {
        // vector<vector<int>> matrix(n, vector<int>(n, 0));

        // int top = 0, bottom = n - 1;
        // int left = 0, right = n - 1;
        // int num = 1;

        // while (top <= bottom && left <= right) {
        //     for (int j = left; j <= right; j++)
        //         matrix[top][j] = num++;
        //     top++;
        //     for (int i = top; i <= bottom; i++)
        //         matrix[i][right] = num++;
        //     right--;
        //     if (top <= bottom) {
        //         for (int j = right; j >= left; j--)
        //             matrix[bottom][j] = num++;
        //         bottom--;
        //     }
        //     if (left <= right) {
        //         for (int i = bottom; i >= top; i--)
        //             matrix[i][left] = num++;
        //         left++;
        //     }
        // }
        // return matrix;

        // optimal
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1;
        fillSpiral(matrix, 0, n - 1, 0, n - 1, num);
        return matrix;
    }
};