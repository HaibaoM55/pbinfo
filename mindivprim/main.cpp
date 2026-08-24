int minDivPrim(int n){
    for(int d = 2; d*d <= n; d++){
        while(n % (d*d) == 0){
			n = n/d;
        }
    }
    return n;
}
