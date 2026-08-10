int cifmax(int x){
    if(x < 10){
    	return x;
    }
	return max(cifmax(x/10), cifmax(x%10));
}
