string intToRoman(int number){
  string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
  int value[]=    {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
  string result="";
  for(int i=0;number!=0;++i){
     if(number>=values[i]){
       result+=values[i];
       number-=numberR[i];
     }
  }
  return result;
}
