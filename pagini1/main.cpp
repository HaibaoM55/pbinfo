bool esteprim(int x){
    if(x < 2) return false;
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}
int pagini(int n){
    if(n % 4 == 0){
        if(esteprim(n/4)){
            return 1;
        }
    }
    return 0;
}
