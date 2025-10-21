int* sumaMinMax(int v[], int n){
	int *rez = new int[2];
    int vmax = 0, vmin=2e9, s=0;
    for(int i = 0; i < n; i++){
    	vmax = max(vmax, v[i]);
        vmin = min(vmin, v[i]);
        s += v[i];
    }
    rez[0] = s-vmax;
    rez[1] = s-vmin;
    return rez;
}
