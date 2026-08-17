void P(int &n, int c){
    int x = 0, exp = 1;
    do{
        if(n%10 != c){
        	x = (n%10)*exp+x;
        	exp = exp*10;
        }
        n = n/10;
    }while(n);
    n = x;
}
