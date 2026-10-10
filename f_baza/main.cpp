bool baza(int n, int b){
    if(n == 0) return true;
    if(n%10 >= b) return false;
    return baza(n/10, b);
}
