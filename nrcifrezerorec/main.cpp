int nr_cif_zero(int x){
    if(x <= 9){
    	return (int)(x%10==0);
    }
	return (int)(x%10==0)+nr_cif_zero(x/10);
}
