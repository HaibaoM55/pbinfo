void valuri(int n, int v[]){
	int imp = 1, par = 2*n;
    for(int i = 0; i < 2*n; i++){
        if(i % 2 == 0){
        	v[i] = imp;
            imp += 2;
        }else{
        	v[i] = par;
            par -= 2;
        }
    }
}
