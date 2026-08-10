long long suma(int* v, int n){
    if(n == 0){
    	return 0;
    }
    return v[n-1]+suma(v, n-1);
}
