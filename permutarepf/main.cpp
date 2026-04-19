int permutare(int a[], int n){
    bool f[104] = {false};
    for(int i = 1; i <= n; i++){
    	f[i] = false;
    }
    for(int i = 0; i < n; i++){
        f[a[i]] = true;
        if(a[i] == i+1){
        	return 0;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!f[i]){
     		return 0;
        }
    }
    return 1;
}
