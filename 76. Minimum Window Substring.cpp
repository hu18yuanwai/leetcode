class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mymap;
        for(int i=0;i<t.size();i++){
            ++mymap[t[i]];
        }


        int l=0,minl=0,cnt=0,minsize=s.size()+1;

        for(int i=0;i<s.size();i++){
            if(mymap.find(s[i])!=mymap.end()){

                if((--mymap[s[i]])>=0) cnt++; //还有这里

                while(cnt==t.size()){
                    if(i-l+1<minsize){
                        minl=l;
                        minsize=i-l+1;
                    }

                    if(mymap.find(s[l])!=mymap.end()){
                        if((++mymap[s[l]])>0) --cnt; //这里错了
                    }
                    ++l;
                }
            }
        }


        if(minsize>s.size()) return "";
        return s.substr(minl,minsize);
    }
};
