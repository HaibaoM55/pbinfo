int cifmin(int x){
    if(x < 10){
    	return x;
    }
	return min(cifmin(x/10), cifmin(x%10));
}
