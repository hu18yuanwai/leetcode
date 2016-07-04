class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len=citations.size();
        if(len==0) return 0;
        sort(citations.begin(),citations.end());
        std::vector<int> v(len+1,0);
        for(int i=0;i<len;i++){
        	if(citations[i]>=len)
        		v[len]++;
        	else
        		v[citations[i]]++;
        }

        for(int i=len-1;i>=0;i--)
        	v[i]+=v[i+1];

        for(int i=len;i>=0;i--)
        	if(v[i]>=i) return i;
        return 0;
    }
};