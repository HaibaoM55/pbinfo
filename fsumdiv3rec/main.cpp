int sum3(int *v, int n){
    if(n == 1){
        return (int)(v[n-1]%3==0)*(v[n-1]);
    }
    return (int)(v[n-1]%3==0)*(v[n-1])+sum3(v, n-1);
}
