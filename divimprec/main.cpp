int DivImpRec(int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return DivImpRec(n/2);
    }
    return n;
}
