class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
        {
            return;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        // 第一步：记下第一行和第一列中是否有0。
        bool zeroInFirstRow = false;
        bool zeroInFirstColumn = false;
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                zeroInFirstRow = true;
                break;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                zeroInFirstColumn = true;
                break;
            }
        }

        // 第二步：利用第一行和第一列作为辅助空间，记下哪些行和哪些列需要设置成0。
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 第三步：根据记录的信息，设置行或列。
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 最后，设置第一行和第一列。
        if (zeroInFirstRow)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (zeroInFirstColumn)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
