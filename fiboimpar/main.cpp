long long Fibo(int n){
    long long f[104];
    f[1] = 1;
    f[2] = 1;
    n-=2;
    if(n <= 0){
    	return 1;
    }
    for(int i = 3; i <= 100; i++){
    	f[i] = f[i-1]+f[i-2];
        if(f[i] % 2 != 0){
        	n--;
        }
        if(n == 0){
        	return f[i];
        }
    }
}
