int nr_cif(int n, int k){
    int nr = 0;
    do{
        if(n%10 == 0){
        	n = n/10;
            continue;
        }
        if(k % (n%10) == 0){
        	nr++;
        }
        n = n/10;
    }while(n);
    return nr;
}
