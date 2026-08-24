int suma(int a, int b){
    int s = 0;
    for(int i = 1; i*i <= a; i++){
        if(a % i == 0){
            if(b % i == 0){
            	s += i;
            }
            if(i*i < a){
                if(b % (a/i) == 0){
                	s += a/i;
                }
            }
        }
    }
    return s;
}
