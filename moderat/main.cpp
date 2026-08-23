int Moderat(int n){
    int nr = 0;
    int faza = 0;
    for(int d = 2; d*d <= n; d++){
        if(faza == 1){
        	return 0;
        }
        if(n % d == 0){
        	nr++;
            faza++;
        }
    }
    return nr == 1;
}
