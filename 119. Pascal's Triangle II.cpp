class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int>ret;
        if(rowIndex<0) return ret;
        ret.push_back(1);
        if(rowIndex==0) return ret;

        for(int i=0;i<=rowIndex-1;i++){
        	vector<int> temp(ret);
        	ret.clear();
        	ret.push_back(1);
    		for(int i=0,j=1;j<temp.size();i++,j++)
    			ret.push_back(temp[i]+temp[j]);
    		ret.push_back(1);
        }
        return ret;
    }
};

//学会从后往前遍历 http://www.cnblogs.com/felixfang/p/3865135.html

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int>ret;
        if(rowIndex<0) return ret;
        ret.push_back(1);
        if(rowIndex==0) return ret;

        for(int i=0;i<=rowIndex-1;i++){
        	ret.push_back(1);
    		for(int i=ret.size()-2,j=ret.size()-3;j>=0;i--,j--)
    			ret[i]=ret[i]+ret[j];
        }
        return ret;
    }
};