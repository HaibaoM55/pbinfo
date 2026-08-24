int multiplu(int n){
	int x = n;
    for(int d = 2; d*d <= n; d++){
        int exp = 0;
        while(n % d == 0){
        	n = n/d;
        	exp++;
        }
        if(exp % 2 == 1){
        	x = x*d;
        }
    }
    x = x*n;
    return x;
}
