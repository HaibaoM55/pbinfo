int PM(int n){
    int nrc = 0;
    int v[14];
    do{
        nrc++;
        v[nrc] = n%10;
        n =n/10;
    }while(n);
    if(nrc % 2 == 1){
        int z = nrc;
        v[0] = 0;
        for(int i = 1; i <= z; i++){
            if(v[i] != v[z] || v[i] <= v[i-1]){
                return 0;
            }
            z--;
        }
        return 1;
    }
    return 0;
}
