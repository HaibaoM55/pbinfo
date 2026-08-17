void inserare(int &n){
	long long x = 0, exp = 1;
    do{
        x = exp*(n%10)+x;
        exp = exp*10;
        if(n >= 10){
            x = exp*abs(n/10%10-n%10)+x;
            exp = exp*10;
        }
        n = n/10;
    }while(n);
	n = x;
}
