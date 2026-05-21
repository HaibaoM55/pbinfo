void sub(int n, int v[], int x){
    int c[56];
    int z = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == x){
            c[z] = x;
            z++;
        }
    }
    for(int i = 0; i < n; i++){
        if(v[i] != x){
            c[z] = v[i];
            z++;
        }
    }
    for(int i = 0; i < n; i++){
        v[i] = c[i];
    }
}
