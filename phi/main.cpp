int Phi(int n){
    int r = n , d = 2;
    while(n > 1){
        if(n % d == 0){
            r = r / d * (d - 1);
            while(n % d == 0){
                n = n/d;
            }
        }
        d++;
        if(d * d > n){
            d = n;
        }
    }
    return r;
}
