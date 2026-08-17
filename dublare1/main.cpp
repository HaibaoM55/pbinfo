void dublare1(int &n){
	int p = n;
    int x = 10;
    while(p > 9){
    	p = p/10;
    	x = x*10;
    }
    n = x*p+n;
}
