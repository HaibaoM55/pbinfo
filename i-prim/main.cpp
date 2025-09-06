int i_prim(int n){
	int a, b;
    for(a=n; a <= 2e9; a++){
    	bool esteprim = true;
        for(int i = 2; i*i <= a; i++){
            if(a % i == 0){
            	esteprim = false;
                break;
            }
        }
        if(esteprim){
        	break;
        }
    }
    for(b=n; b >= 1; b--){
    	bool esteprim = true;
        for(int i = 2; i*i <= b; i++){
            if(b % i == 0){
            	esteprim = false;
                break;
            }
        }
        if(esteprim){
        	break;
        }
    }
    return a-b;
}
