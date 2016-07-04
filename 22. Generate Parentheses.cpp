void generate(int left,int right,string s,vector<string> &strs){
  if(left==0 && right==0) strs.push_back(s);
  if(left>0){
    generate(left-1,right,s+'(',strs);
  }
  if(right>0 && left<right){
    generate(left,right-1,s+')',strs);
  }
}

vector<string> generateParenthesis(int n) {
  vector<string>re;
  generate(n,n,"",re);
  return re;
}
