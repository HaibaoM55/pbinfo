void Impare(int &n){
    int x =0, exp=1;
    do{
        if(n%2==1){
        	n--;
        }
        x = exp*(n%10)+x;
        exp=exp*10;
        n = n/10;
    }while(n);
    n = x;
}
