void sub(int n, int &a, int &b){
    a = -1;
    b = -1;
    for(int i = n-1; i >= 1; i--){
    	bool esteprim = true;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
            	esteprim = false;
                break;
            }
        }
        if(esteprim){
            if(a == -1){
            	a = i;
            }else if(b == -1){
            	b = i;
                break;
            }
        }
    }
}
