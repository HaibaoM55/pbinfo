long long SumProdRec(int n){
    if(n == 0){
        return 0;
    }
    return 1LL*(n-1)*n+SumProdRec(n-1);
}
