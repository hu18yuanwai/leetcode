class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int i,j;
        int CurLength = 0;
        int MaxLength = 0;
        int Len = num.size();
        unordered_map<int,bool> used;
        for(i = 0;i < Len;i++){
            used[num[i]] = false;
        }
        for(i = 0;i < Len;i++){
            if(used[num[i]]){
                continue;
            }
            else{
                used[num[i]] = true;
                CurLength = 1;
                for(j = num[i] + 1;used.find(j) != used.end();j++){
                    CurLength ++;
                    used[j] = true;
                }
                for(j = num[i] - 1;used.find(j) != used.end();j--){
                    CurLength ++;
                    used[j] = true;
                }
                if(CurLength > MaxLength){
                    MaxLength = CurLength;
                }
            }
        }
        return MaxLength;
    }
};