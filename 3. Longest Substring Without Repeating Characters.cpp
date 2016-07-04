#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
	const int tableSize=256;
	unsigned int hashTable[tableSize];

	for(int i=0;i<tableSize;i++){
		hashTable[i]=0;
	}

	int reInt=0;
	int i=0;
	while(i<s.size()){
		int iter=i;

		while(hashTable[s[iter]]==0 && iter<s.size()){ //注意这里iter的范围
			hashTable[s[iter]]=1;
			iter++;
		}

		if(reInt<iter-i){
			reInt=iter-i;
		}
		while(iter>=i){
			hashTable[s[iter]]=0;
			iter--;
		}
		i++;
	}
	return reInt;
}
