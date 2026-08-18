void produs(int a, int &k){
	k = 1;
    int p = 1;
    while(p <= a){
        k+=2;
    	p = p*k;
    }
    k -= 2;
}
