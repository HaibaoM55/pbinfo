void numar(int n, int a[], int &k){
	int vmax = 0, vmin = 2e9;
    for(int i =0; i < n; i++){
    	vmax = max(vmax, a[i]);
        vmin = min(vmin, a[i]);
    }
    int exp = 1, x = vmin;
    do{
        exp = exp*10;
        x = x/10;
    }while(x);
    k = vmax*exp+vmin;
}
