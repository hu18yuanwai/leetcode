class Solution {
public:
    string fractionToDecimal(long long  numerator, long long denominator) {
        if(numerator<0 || denominator<0){
            if(numerator<0 && denominator<0)
                return fractionToDecimal(-numerator,-denominator);
            else{
                string s=fractionToDecimal(abs(numerator),abs(denominator));
                if(s=="0") return s;
                return "-"+s;
            }
        }
        if(numerator==0 || numerator>=denominator){
            long long i=numerator/denominator;
            stringstream ss;
            ss<<i;
            string ret=ss.str();
            if(numerator%denominator==0)
                return ret;
            else{
                string s= fractionToDecimal(numerator%denominator,denominator);
                return ret + s.substr(1);
            }
        }

        string ret="0.";
        long long reminder = numerator;
        int pos = 1;
        map<long long,int> reminderAndPos;
        reminderAndPos[reminder]=pos;
        pos=3;
        while(true){
        	reminder*=10;
        	pos++;
			while(reminder<denominator){
				if(reminder<denominator) reminderAndPos[reminder]=pos;
				reminder*=10;
				pos++;
				ret=ret+"0";
			}

			ret+=char('0'+reminder/denominator);
			reminder=reminder%denominator;
			if(reminder==0) return ret;
			if(reminderAndPos[reminder]) break;
			reminderAndPos[reminder]=pos;
        }

        /*for(map<int,int>::iterator it = reminderAndPos.begin();it!=reminderAndPos.end();it++)
        	cout<<it->first<<" "<<it->second<<endl;*/
        if(reminderAndPos[reminder]==1) return ret.insert(reminderAndPos[reminder]+1,"(")+")";
        return ret.insert(reminderAndPos[reminder]-1,"(")+")";
    }
};



//别人的方法

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // special cases
        if(numerator == 0)
            return "0";
        string ret = "";
        // type conversion in case of INT_MIN
        long long n = numerator;
        long long d = denominator;
        // sign
        int sign = 1;
        bool digit = false;
        if((n<0) ^ (d<0))
            sign = -1;
        n = abs(n);
        d = abs(d);
        unordered_map<long long, int> m;  // numerator --> position
        while(true)
        {
            if(n < d)
            {
                if(digit == false)
                {
                    if(ret == "")
                        ret = "0.";
                    else
                        ret += ".";
                    digit = true;
                }
                n *= 10;
            }
            int r = n - n/d*d;
            if(r == 0)
            {
                ret += to_string(n/d);
                if(sign == -1)
                    ret = "-" + ret;
                return ret;
            }
            else
            {
                if(digit == true)
                {// check recurring
                    if(m.find(n) == m.end())
                    {
                        ret += to_string(n/d);
                        m[n] = ret.size()-1;
                    }
                    else
                    {
                        int pos = m[n];
                        ret = ret.substr(0, pos) + "(" + ret.substr(pos) + ")";
                        if(sign == -1)
                            ret = "-" + ret;
                        return ret;
                    }
                }
                else
                {
                    ret += to_string(n/d);;
                }
                n = r;
            }
        }
    }
};
