class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num>=4){
            int temp=num>>2;
            if(num==(temp<<2)) num=temp;
            else return false;
        }
        if(num==1) return true;
        return false;
    }
};
