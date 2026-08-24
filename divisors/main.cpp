int NrDiv(int n){
	int nr = 0;
    for(int d = 1; d*d <= n; d++){
        if(n % d == 0){
        	nr++;
            if(d*d < n){
            	nr++;
            }
        }
    }
    return nr;
}
int NextNrDiv(int n){
    int nr = NrDiv(n);
    n++;
    while(NrDiv(n) != nr){
    	n++;
    }
    return n;
}
int PrevNrDiv(int n){
	int nr = NrDiv(n);
    n--;
    while(NrDiv(n) != nr){
    	n--;
        if(n == 0){
        	return -1;
        }
    }
    return n;
}
