bool eprim(int k){
    if(k < 2){
    	return false;
    }
    for(int i = 2; i*i <= k; i++){
        if(k % i == 0){
        	return false;
        }
    }
    return true;
}
void P(int x[], int n, int &s){
    s = 0;
    for(int i = 0; i < n; i++){
    	s += (int)eprim(x[i])*x[i];
    }
}
