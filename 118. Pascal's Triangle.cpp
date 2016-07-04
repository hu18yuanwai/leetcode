class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows<=0) return ret;
        vector<int> temp;
        temp.push_back(1);
        ret.push_back(temp);
        if(numRows==1) return ret;
        temp.push_back(1);
        ret.push_back(temp);
        if(numRows==2) return ret;

        temp.clear();
        ret=generate(numRows-1);
        temp.push_back(1);
        int len=ret.size();
        for(int i=0;i<ret[len-1].size()-1;i++)
        	temp.push_back(ret[len-1][i]+ret[len-1][i+1]);
        temp.push_back(1);
        ret.push_back(temp);
        return ret;
    }
};


//非递归，速度更快
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vec;
        if (numRows == 0)
        {
            return vec;
        }

        vec.push_back(vector<int>{1});
        if (numRows == 1)
        {
            return vec;
        }

        for (int i = 1; i < numRows; i++)
        {
            vec.push_back(next(vec[i - 1]));
        }
        return vec;
    }

private:
    vector<int> next(const vector<int> &vec)
    {
        vector<int> res;
        res.push_back(vec[0]);

        for (int i = 0, j = 1; j < vec.size(); i++, j++)
        {
            res.push_back(vec[i] + vec[j]);
        }

        res.push_back(vec[vec.size() - 1]);
        return move(res);
    }
};