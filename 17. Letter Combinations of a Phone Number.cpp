vector<string> letterCombinations(string digits) {
  string str[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  vector<string>restring;
  if(digits.size()==0)
    return restring;
  for(int i=0;i<digits.size();i++)
    if(digits[i]>'9' || digits[i]<'2')
      return restring;

  string s=str[digits[0]-'0'-2];
  if(digits.size()==1){
    for(int i=0;i<s.size();i++){
      string s1;
      s1+=s[i];
      restring.push_back(s1);
    }
  }
  else  if(digits.size()>1){
    for(int i=0;i<s.size();i++){
      vector<string> ss=letterCombinations(digits.substr(1,digits.size()-1));
      for(int j=0;j<ss.size();j++){
        restring.push_back(s[i]+ss[j]);
      }
    }
  }
  return restring;
}
