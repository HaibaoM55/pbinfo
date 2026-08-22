int CautaPoz(int a[], int n){
    int s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++){
    	s2 += a[i];
    }
    int difmin = 2e9, difmini=0;
    for(int p = 0; p < n; p++){
    	s1 += a[p];
        s2 -= a[p];
        if(abs(s2-s1) < difmin){
        	difmin = abs(s2-s1);
            difmini = p;
        }
    }
    return difmini;
}
