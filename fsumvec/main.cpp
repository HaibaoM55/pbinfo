int suma(int v[], int n, int i, int j){
    int s = 0;
    for(int x = 1; x <= n; x++){
    	s += v[x];
    }
    for(int x = i; x <= j; x++){
   		s -= v[x];
    }
    return s;
}
