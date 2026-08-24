bool eprim(int n){
    if(n < 2){
    	return false;
    }
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
        	return false;
        }
    }
    return true;
}
int nr_prim(int n){
    n++;
    while(!eprim(n)){
    	n++;
    }
    return n;
}
