bool isMatch(char a,char b){
  if(a=='{' && b=='}') return true;
  if(a=='[' && b==']') return true;
  if(a=='(' && b==')') return true;
  return false;
}
bool isValid(string s) {
    if(s.size()==0)
      return false;
    stack<char>charStack;
    charStack.push(s[0]);
    for(int i=1;i<s.size();i++){
      if(s[i]=='(' || s[i]=='[' || s[i]=='{')
        charStack.push(s[i]);
      else{
        if(!charStack.empty() && isMatch(charStack.top(),s[i]))
          charStack.pop();
        else
          return false;
      }
    }
    if(charStack.size()==0)
      return true;
    return false;
 }
