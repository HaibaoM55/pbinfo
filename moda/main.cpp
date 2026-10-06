void moda(int n, int &pc){
    pc = 0;
    int nrc = 0;
    int v[14];
    do{
        nrc++;
        v[nrc] = n%10;
        n = n/10;
    }while(n);
    for(int i = nrc; i >= 0; i--){
        pc++;
        if(v[i] % 2 == 0){
            return;
        }
    }
}
