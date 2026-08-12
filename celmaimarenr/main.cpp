int cmmnr(int x){
    int f[10]={0,0,0,0,0,0,0,0,0,0};
    do{
        f[x%10]++;
        x = x/10;
    }while(x);
    int nr = 0;
    for(int i = 9; i >= 0; i--){
        while(f[i] > 0){
            nr=nr*10+i;
            f[i]--;
        }
    }
    return nr;
}
