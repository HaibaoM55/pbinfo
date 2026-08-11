int IncDecRec(int n){
    if(n < 10){
        if(n % 2 == 0) return n+1;
        return n-1;
    }
    if(n % 2 == 0) return n%10+1+IncDecRec(n/10)*10;
    return n%10-1+IncDecRec(n/10)*10;
}
