void secventa(int &n){
    int x = 0, exp = 1;
    do{
        if(n>=10 && n%10==n/10%10 && n%10 == 2){
        	x = exp*20+x;
            exp = exp*100;
            n = n/10;
        }else{
        	x = exp*(n%10)+x;
        	exp = exp*10;
        }
        n = n/10;
    }while(n);
    n = x;
}
