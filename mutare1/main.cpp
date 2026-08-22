void aranjare(int v[], int n){
	int par[10004];
    int imp[10004];
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0){
        	imp[0]++;
            imp[imp[0]] = v[i];
        }else{
            par[0]++;
            par[par[0]] = v[i];
        }
    }
    for(int i = 0; i < par[0]; i++){
    	v[i] = par[i+1];
    }
    for(int i = par[0]; i < n; i++){
    	v[i] = imp[i-par[0]+1];
    }
}
