class Solution {
public:
    int countPrimes(int n) {
    	if(n<2) return 0;
        vector<int>f(n+1,0);
        f[0]=1;
        f[1]=1;
        for(int i=0;i<=n;i++){
        	if(f[i]==0){
        		for(int j=i*2;j<n;j+=i)
        			f[j]=1;
        	}
        }
        int count=0;
        for(int i=0;i<n;i++)
        	if(f[i]==0) count++;
        return count;
    }
};

class Solution {
public:
    int countPrimes(int n) {
    	if(n<2) return 0;
    	if(n==2) return 1;
    	vector<int>prime;
    	prime.push_back(2);
    	int count=1;
    	for(int i=3;i<n;i++){
    		if(isPrime(i,prime)) count++;
    	}
    	return count;
    }

    bool isPrime(int num,vector<int>&prime){
    	for(int i=0;i<prime.size();i++)
    		if(num%prime[i]==0) return false;
    	prime.push_back(num);
    	return true;
    }
};


class Solution {
public:
    int countPrimes(int n) {
   	int count = 0;
   	for (int i = 1; i < n; i++) {
      	if (isPrime(i)) count++;
   	}
   		return count;
	}

 	bool isPrime(int num) {
   		if (num <= 1) return false;
   		for (int i = 2; i * i <= num; i++) {
      		if (num % i == 0) return false;
   		}
   		return true;
	}
};


class Solution {
public:
    vector<int> prim_vec;
    bool isprime(int n)
    {
	if (n < 2)		
	return false;
	if (n == 2)
		return true;
	if(n %2 == 0)
	    return false;
	int sq = sqrt(n);
	int len = prim_vec.size();
	for (int index=0; index<len;index++)
	{
	    int tmp = prim_vec[index];
	    if(tmp > sq)
	        break;
		if (n % tmp == 0)
			return false;
	}
	return true;
    }
    int countPrimes(int n) {
        int i =0, count=0;
	for (i=1; i<n; i++)
	{
		if (isprime(i))
		{
			count++;
			prim_vec.push_back(i);
		}
	}
	return count;
    }
};





