void nr_cif_zero(int n, int &nr){
    if(n >= 10){
    	nr_cif_zero(n/10, nr);
    }else{
     	nr = 0;
    }
    if(n % 10 == 0){
    	nr++;
    }
}
