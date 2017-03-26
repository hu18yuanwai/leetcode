class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();

        // cuts[i]表示s[0, i)划分成palindrome需要几次cut。
        vector<int> cuts(n + 1);
        for (int i = 0; i < cuts.size(); i++)
        {
            cuts[i] = i - 1;
        }

        // palindrome[i][j]表示s[i, j)是否为palindrome。
        vector<vector<bool>> palindrome(n, vector<bool>(n + 1, false));
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[i - 1] == s[j] && (i - j <= 2 || palindrome[j + 1][i - 1]))
                {
                    palindrome[j][i] = true;
                    cuts[i] = min(cuts[i], cuts[j] + 1);
                }
            }
        }
        return cuts[n];
    }
};


class Solution
{
public:
    int minCut(string s)
    {
        int cuts = 0;
        queue<int> starts;
        starts.push(0);  // 0是字符串首字符的下标，表示从字符串开头进行处理。
        vector<bool> visited(s.size(), false);

        while (true)
        {
            queue<int> nextStarts;
            while (!starts.empty())
            {
                auto pos = starts.front();
                starts.pop();

                for (int i = s.size() - 1; i >= pos; i--)
                {
                    if (!visited[i] && isPalindrome(s, pos, i))
                    {
                        if (i == s.size() - 1)
                        {
                            return cuts;
                        }
                        nextStarts.push(i + 1);
                    }
                }
                visited[pos] = true;
            }
            cuts++;
            starts.swap(nextStarts);
        }
        return cuts;
    }

private:
    bool isPalindrome(string &s, int first, int last)
    {
        for (int i = first, j = last; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
};
