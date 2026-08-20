void duplicare(int &n){
	int x = 0, exp = 1;
    do{
        if(n % 2 == 0){
        	x = exp*((n%10)/2)+x;
            exp = exp*10;
        }
        x = exp*(n%10)+x;
        exp = exp*10;
        n = n/10;
    }while(n);
    n = x;
}
