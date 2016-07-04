string reverse(string &s){
	string s1=s;
	for(int i=s.size()-1;i>=0;i--)
		s1[s.size()-1-i]=s[i];
	return s1;
}

string addBinary(string &a, string &b) {
    if(a=="" && b=="") return "0";
    else if(a=="") return b;
    else if(b=="") return a;
    int lena=a.size()-1,lenb=b.size()-1;
    string s="";
    int c=0;
    while(lena>=0&&lenb>=0){
    	char temp=a[lena]-'0'+b[lenb]+c;
    	if(temp=='3'){
    		s+='1';
    		c=1;
		}
		else if(temp=='2'){
			s+='0';
			c=1;
		}
		else if(temp=='1'){
			s+='1';
			c=0;
		}
		else if(temp=='0'){
			s+='0';
			c=0;
		}
		lena--;
		lenb--;
	}

	while(lena>=0){
		char temp=a[lena]+c;
		if(temp=='3'){
    		s+='1';
    		c=1;
		}
		else if(temp=='2'){
			s+='0';
			c=1;
		}
		else if(temp=='1'){
			s+='1';
			c=0;
		}
		else if(temp=='0'){
			s+='0';
			c=0;
		}
		lena--;
	}

	while(lenb>=0){
		char temp=b[lenb]+c;
		if(temp=='3'){
    		s+='1';
    		c=1;
		}
		else if(temp=='2'){
			s+='0';
			c=1;
		}
		else if(temp=='1'){
			s+='1';
			c=0;
		}
		else if(temp=='0'){
			s+='0';
			c=0;
		}
		lenb--;
	}
	if(c==1) s+=(c+'0');
	return reverse(s);
}
