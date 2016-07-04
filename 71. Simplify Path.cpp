class Solution {
public:
   void cutoff(string path,vector<string> &cult){
     int front=0,back=1;
     while(front<path.size() && back<path.size()){
       while(front+1<path.size()){
         if(path[front+1]!='/') break;
         else front++;
       }
       back=front+1;
       while(back<path.size()){
         if(path[back]=='/') break;
         else back++;
       }
       if(front<path.size() && path.substr(front,back-front)!="/")
          cult.push_back(path.substr(front,back-front));
       front=back;
       back++;
     }
   }
    string simplifyPath(string path) {
      vector<string> cult;
      cutoff(path,cult);
      stack<string> sta;
      sta.push("/");
      for(int i=0;i<cult.size();i++){
        if(cult[i]=="/.") continue;
        else if(cult[i]=="/.."){
          if(sta.top()!="/")
            sta.pop();
        }
        else sta.push(cult[i]);
      }
      string s="";
      while(!sta.empty()){
        string top=sta.top();
        sta.pop();
        if(s!="" && top=="/") continue;
        s=top+s;
      }
      return s;
    }
};


class Solution{
  public:
      string simplifyPath(string path){
          stack<string> ss;
          for(int i = 0; i < path.size(); ){
             while(i < path.size() && '/' == path[i])
                 ++ i;
             string s = "";
             while(i < path.size() && path[i] != '/')
                 s += path[i ++];
             if(".." == s && !ss.empty())
                 ss.pop();
             else if(s != "" && s != "." && s != "..")
                              ss.push(s);
         }
         if(ss.empty())
             return "/";
         string s = "";
         while(!ss.empty()){
             s = "/" + ss.top() + s;
             ss.pop();
         }
         return s;
     }
};
