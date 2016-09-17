#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
    	int len =ratings.size();
    	if(len<=1) return len;
    	vector<int> candy(len,1);      
    	for(int i=1;i<len;i++){
    		if(ratings[i-1]<ratings[i])
    			candy[i] = candy[i-1]+1;
    	}  

    	for(int j=len-1;j>=0;j--){
    		if(ratings[j]<ratings[j-1])
    			candy[j-1] = max(candy[j]+1,candy[j-1]);
    	}

    	int ret = 0;
    	for(int i=0;i<len;i++)
    		ret+=candy[i];
    	return ret;
    }
};