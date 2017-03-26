class Solution
{
public:
    void solve(vector<vector<char>>& board)
    {
        if (board.empty())
        {
            return;
        }

        auto m = board.size();
        auto n = board[0].size();

        // 从4个边界开始，把所有能与边界连通的'0'，临时改写成空格。
        vector<pair<int, int>> start {{0, 0}, {m - 1, 0}, {0, 0}, {0, n - 1}};
        vector<pair<int, int>> step {{0, 1}, {0, 1}, {1, 0}, {1, 0}};
        for (auto k = 0; k < start.size(); k++)
        {
            for (auto i = start[k].first, j = start[k].second; i < m && j < n; i += step[k].first, j += step[k].second)
            {
                if (board[i][j] == 'O')
                {
                    markUnsurroundedRegion(board, i, j);
                }
            }
        }

        for (auto i = 0; i < m; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                board[i][j] = (board[i][j] == ' ' ? 'O' : 'X');
            }
        }
    }

private:
    void markUnsurroundedRegion(vector<vector<char>> &board, int row, int col)
    {
        auto m = board.size();
        auto n = board[0].size();
        queue<pair<int, int>> pos;
        pos.push({row, col});
        while (!pos.empty())
        {
            auto p = pos.front();
            pos.pop();
            if (0 <= p.first && p.first < m && 0 <= p.second && p.second < n && board[p.first][p.second] == 'O')
            {
                board[p.first][p.second] = ' ';
                pos.push({p.first - 1, p.second});
                pos.push({p.first, p.second + 1});
                pos.push({p.first + 1, p.second});
                pos.push({p.first, p.second - 1});
            }
        }
    }
};
