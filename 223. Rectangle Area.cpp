int overLab(int A, int B, int C, int D, int E, int F, int G, int H){
	int left=max(A,E);
	int right=min(C,G);

	int down=max(B,F);
	int up=min(D,H);

	if(left>right) return 0;
	if(up<down) return 0;
	return (right-left)*(up-down);
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int s1= (C-A)*(D-B)+(G-E)*(H-F);
	return s1-overLab(A,B,C,D,E,F,G,H);
}
