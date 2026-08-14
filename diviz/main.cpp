int diviz(int n){
    int vmax = 0;
    for(int i = 1; i*i <= n; i++){
        if(n % (i*i) == 0){
        	vmax = max(vmax, i*i);
        }
    }
    return vmax;
}
