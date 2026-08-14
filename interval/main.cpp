int interval(int a[], int n){
    if(a[0] > a[n-1]){
    	swap(a[0], a[n-1]);
    }
    int nr = 0;
    for(int i = 0; i < n; i++){
        if(a[0] <= a[i] && a[i] <= a[n-1]){
			nr++;
        }
    }
    return nr;
}
