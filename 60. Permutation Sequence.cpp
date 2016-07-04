//由于回溯法不满足字典序，所以下面做有问题
class Solution {
public:
	void backTrack(string &ret,int &count,string& cur,int N){
		if(N>=cur.size()){
			count--;
			if(count==0)
			ret=cur;
			return;
		}
		else{
			for(int i=N;i<cur.size();i++){
				swap(cur[i],cur[N]);
				backTrack(ret,count,cur,N+1);
				swap(cur[i],cur[N]);
			}
		}
	}

   string getPermutation(int n, int k) {
   		string cur(n,'0');
    	for(int i=0;i<n;i++) cur[i]='0'+i+1;
    	string ret;
		int count=k;
    	backTrack(ret,count,cur,0);
    	return ret;
    }
};

//利用nextPermutation
string getPermutation(int n, int k) {
	string cur(n,'0');
	for(int i=0;i<n;i++) cur[i]='0'+i+1;
	k=k-1;
	while(k--){
		nextPermutation(cur);
	}
	return cur;
}

void nextPermutation(string &num)
  {
     if(num.size() == 0 || num.size() == 1)
          return ;

      for(int i = num.size() - 1; ; )
     {
         int ii = i --;
         if(num[i] < num[ii])
         {
             int j = num.size();
             while(!(num[i] < num[-- j]));
             swap(num[i], num[j]);
             reverse(num.begin() + ii, num.end());
             break;
         }
         if(i == 0)
         {
             reverse(num.begin(), num.end());
             break;
         }
     }
 }
