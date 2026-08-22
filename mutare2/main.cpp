bool esteprim(int x){
    if(x < 2){
   		return false;
    }
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
        	return false;
        }
    }
    return true;
}
void modificare(int v[], int n){
	int par[10004];
    int imp[10004];
    for(int i = 0; i < n; i++){
        if(!esteprim(v[i])){
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
