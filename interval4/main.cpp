bool esteprim(int x){
    if(x < 2){
        return false;
    }
    for(int i = 2; i*i <= x;i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int interval(int n){
    int x=n;
    bool ok = false;
    for(int i = n; ok == false; i++){
        ok = esteprim(i);
        if(ok){
            x = i;
        }
    }
    return x + 1;
}
