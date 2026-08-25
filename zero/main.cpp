void zero(int n, int v[]){
    int imp[54], par[54];
    par[0] = imp[0] = 0;
    for(int i = 1; i <= 2*n; i++){
        if(v[i] % 2 == 0){
        	par[0]++;
            par[par[0]] = v[i];
        }else{
            imp[0]++;
            imp[imp[0]] = v[i];
        }
    }
    for(int i = 1; i <= 2*n; i++){
        if(i % 2 == 0){
        	v[i] = par[i/2];
        }else{
        	v[i] = imp[i/2+1];
        }
    }
}
