int sufmax(int n){
    if(n == 0){
    	return 0;
    }
    if(n % 10 != n/10%10){
    	return n%10;
    }
    return sufmax(n/10)*10+n%10;
}
