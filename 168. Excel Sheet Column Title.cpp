class Solution {
public:
    string convertToTitle(int n) {
    	string ret="";
    	while(n>0){
    		ret=(char)((n-1)%26+'A') + ret;
    		n=(n-1)/26;
    	}
    	return ret;
    }
};


class Solution {
public:
    string convertToTitle(int n) {
        string s;
        
        if (n <= 0)
        {
            return s;
        }
        
        if (n > 0 && n <= 26)
        {
            s.push_back((char)('A' + n - 1));
            return s;
        }
        else if (0 == n%26)
        {
            s += convertToTitle((n-26)/26);
            s += convertToTitle(26);
            return s;
        }
        else
        {
            s += convertToTitle(n/26);
            s += convertToTitle(n%26);
            return s;
        }
    }
};