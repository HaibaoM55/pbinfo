void shift(int v[], int n){
    int aux = v[0];
    for(int i = 0; i < n-1; i++){
    	v[i] = v[i+1];
    }
    v[n-1] = aux;
}
