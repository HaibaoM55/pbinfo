void perm(int &n){
	int x = 0, exp = 1;
    while(n > 9){
    	x = exp*(n%10)+x;
        n = n/10;
        exp = exp*10;
    }
    x = x*10+n;
    n = x;
}
