int PermD(int a[], int n){
	int fc[1004], fr[1004];
    for(int i = 0; i <= 1000; i++){
        fc[i] = 0;
        fr[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        fc[a[i]/1000]++;
        fr[a[i]%1000]++;
    }
    for(int i = 1; i < n; i++){
    	fc[i/1000]++;
        fr[i%1000]++;
    }
    for(int i = 1; i <= n-1; i++){
        if(fc[i/1000] % 2 != 0 && fr[i%1000] % 2 != 0){
        	return i;
        }
    }
}
