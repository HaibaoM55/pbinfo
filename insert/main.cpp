void Insert(int a[], int &n){
    int nri = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 1){
            nri++;
        }
    }
    int z = n+nri;
    for(int j = n-1; j >= 0; j--){
    	if(a[j] % 2 != 0){
        	a[j+nri] = a[j]*2;
            nri--;
        }
        a[j+nri] = a[j];
    }
    n = z;
}
