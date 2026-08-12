int suma(int *v, int n, int i, int j){
    if(n == 0){
        return 0;
    }
    int p = 0;
    if(n < i || j < n){
        p = v[n];
    }
    return p+suma(v, n-1, i, j);
}
