int cifreImpare(int n){
	int exp = 1, x = 0;
    bool ok = true;
    do{
        if(n % 2 == 0){
        	x = exp*(n%10)+x;
            exp = exp*10;
        }else{
            ok = false;
        }
   		n = n/10;
    }while(n);
    if(ok || exp == 1) return -1;
    return x;
}
