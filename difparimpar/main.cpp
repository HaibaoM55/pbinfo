int DifParImpar(int n){
    if(n < 10){
        if(n % 2 == 0) return 1;
        return -1;
    }
    return DifParImpar(n%10)+DifParImpar(n/10);
}
