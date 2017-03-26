class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_map<string,int> geneMap;
        for(int i=0;i<=s.size()-10;i++){
            string str = s.substr(i,10);
            geneMap[str]++;
            if(geneMap[str]==2) ret.push_back(str);
        }
        return ret;
    }
};


//优化存储
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;
        const int len = 10;

        int hashOfSeq = 0;
        for (int i = 0; i < s.size() && i < len - 1; i++)
        {
            hashOfSeq = (hashOfSeq << 3) | (s[i] & 0x7);
        }

        unordered_map<int, int> seqs;  // {seq, cnt}
        for (int i = len - 1; i < s.size(); i++)
        {
            hashOfSeq = (hashOfSeq << 3) & 0x3fffffff | (s[i] & 0x7);
            auto cnt = ++seqs[hashOfSeq];
            if (cnt == 2)
            {
                res.push_back(s.substr(i - (len - 1), len));
            }
        }
        return res;
    }
};
