int count(double a[], int n){
	double medie = 0;
    for(int i = 0; i < n; i++){
     	medie += a[i];
    }
    medie = medie/(1.0*n);
    int nr = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= medie){
        	nr++;
        }
    }
    return nr;
}
