void nextPermutation(vector<int> &num)

  {
     if(num.size() == 0 || num.size() == 1)
          return ;

      for(int i = num.size() - 1; ; )
     {
         int ii = i --;
         if(num[i] < num[ii])
         {
             int j = num.size();
             while(!(num[i] < num[-- j]));
             swap(num[i], num[j]);
             reverse(num.begin() + ii, num.end());
             break;
         }
         if(i == 0)
         {
             reverse(num.begin(), num.end());
             break;
         }
     }
 }
