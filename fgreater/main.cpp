int FGreater(int a[], int n, int x){
    int vmin = -1;
    for(int i = 0; i < n; i++){
        if(a[i] > x){
            if(a[i] < vmin || vmin == -1){
            	vmin = a[i];
            }
        }
    }
    return vmin;
}
