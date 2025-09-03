bool a_prim(int x){
    int nr = 0;
    for(int i = 2; i*i < x; i++){
        while(x % i == 0){
            x = x/i;
            nr++;
        }
    }
    if(x > 1){
        nr++;
    }
    if(nr == 2){
        return 1;
    }
    return 0;
}
