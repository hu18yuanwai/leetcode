class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(len<=0 ||(s[0]=='0' )) return 0;
        int foward=1,back=1;
        if(len==1) return foward;
        if(s[1]=='0'){
            if(cal(s[0],s[1])>20){
                back = 1;
                foward =0;
            }
        }
        else{
            if(cal(s[0],s[1])<=26){
                foward=2;
            }
        }

        for(int i=2;i<s.size();i++){
            if(s[i]=='0'){
                if(s[i-1]>='3' || s[i-1]=='0'){
                    //back = foward;
                    foward =0;
                    return foward;
                }
                else{
                	int t = foward;
                     foward = back;
                     back =t;
                }
            }
            else if(s[i]<='6' && s[i]>'0'){
                if(s[i-1]=='1' || s[i-1]=='2'){
                    int temp = foward;
                    foward+=back;;
                    back = temp;
                }
                else{
                    back = foward;
                }
            }
            else{
                if(s[i-1]=='1'){
                    int temp = foward;
                    foward+=back;
                    back = temp;
                }
            }
        }
        return foward;
    }
private:
    int cal(char a, char b){
        return (a-'0')*10+(b-'0');
    }
};



int numDecodings(string s) {
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1]
    int r1 = 1, r2 = 1;

    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}
