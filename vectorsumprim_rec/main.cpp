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
void P(int *v, int n, int &s){
    if(n == 0){
    	s = 0;
    }else{
   		P(v, n-1, s);
    }
    if(esteprim(v[n-1])){
    	s += v[n-1];
    }
}
