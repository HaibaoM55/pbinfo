void Plus(int &n){
    int x = 0, exp = 1;
    do{
        if(n>=10 && n/10%10==2 && n%10 == 5){
            x = exp*26+x;
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
