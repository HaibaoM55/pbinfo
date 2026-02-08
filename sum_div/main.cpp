int sum_div(int x){
    int s = 0;
    for(int i = 1; i*i <= x; i++){
        if(x % i == 0){
        	s += i;
            if(i*i < x){
            	s += x/i;
            }
        }
    }
    return s;
}
