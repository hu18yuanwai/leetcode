边界条件容易出错，比如 i-2)>=0  i-longest[i-1]-1>=0  i-longest[i-1]-2) 导致最后结果变大

int longestValidParentheses(string s) {
  if(s.size()<=1) return 0;
  int lens=s.size(),reMax=0;
  vector<int>longest(lens,0);
  for(int i=1;i<lens;i++){
      if(s[i]==')'){
        if(s[i-1]=='(') {
          longest[i]=((i-2)>=0)?(longest[i-2]+2):2;
          reMax=reMax>longest[i]?reMax:longest[i];
        }
        if(i-longest[i-1]-1>=0 && s[i-1]==')' && s[i-longest[i-1]-1]=='(') {
          longest[i]=longest[i-1]+2+((i-longest[i-1]-2)>0?longest[i-longest[i-1]-2]:0);
          reMax=reMax>longest[i]?reMax:longest[i];
        }
    }
  }
  return reMax;
}



int longestValidParentheses(string s) {
        if(s.length() <= 1) return 0;
        int curMax = 0;
        vector<int> longest(s.size(),0);
        for(int i=1; i < s.length(); i++){
            if(s[i] == ')' && i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                    longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                    curMax = max(longest[i],curMax);
            }
        }
        return curMax;
    }



    int longestValidParentheses(string s)
  {
          int res = 0, l = 0;
         stack<int> si;
        for(int i = 0; i < s.size(); ++ i)
         {
            if(s[i] == '(')
                si.push(i);
             else
             {
                 if(si.empty())
                     l = i + 1;
                else
                 {
                     si.pop();
                     if(si.empty())
                         res = max(res, i - l + 1);
                     else
                         res = max(res, i - si.top());
                }
            }
         }
         return res;
     }
