void num (int n, int v[]){
    if(n == -1){
		return;
	}
    if(v[n-1] <= v[0]){
    	v[n-1] = 0;
    }
    num(n-1, v);
}
