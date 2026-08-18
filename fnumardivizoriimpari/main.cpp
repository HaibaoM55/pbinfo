void nr_div_imp(int n, int &nr){
    nr = 0;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            if(i % 2 == 1){
            	nr++;
            }
            if(i*i < n){
                if((n/i)%2 == 1){
                	nr++;
                }
            }
        }
    }
}
