long long nroot(int n,long long x){
    if(n == 1){
        return abs(x);
    }else if(n == 2){
        return abs(sqrt(x));
    }else if(n == 3){
        return abs(cbrt(x));
    }else if(n == 4){
        return abs(sqrt(sqrt(x)));
    }
    if(x==0){
        return 0;
    }
    for(int i = -4096; i <=4096; i++){
        long long p = 1;
        for(int j = 1; j <= n; j++){
            p = p*i;
        }
        if(p == x){
            return abs(i);
        }
    }
}
