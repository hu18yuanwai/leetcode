class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(),len2=word2.size();

        vector< vector<int> > edit(len1+1,vector<int>(len2+1,0));
        for(int i=0;i<len1+1;i++) edit[i][0]=i;
        for(int i=0;i<len2+1;i++) edit[0][i]=i;

        for(int i=1;i<len1+1;i++){
            for(int j=1;j<len2+1;j++){
                int flag=1;
                if(word1[i-1]==word2[j-1]) flag=0; //not word1[i]==word2[i]
                edit[i][j]=min(edit[i-1][j-1]+flag,min(edit[i-1][j]+1,edit[i][j-1]+1));
            }
        }

        for(int i=1;i<len1+1;i++){
            for(int j=1;j<len2+1;j++){
                cout<<edit[i][j]<<" ";
            }
            cout<<endl;
        }

        return edit[len1][len2];
    }
};
