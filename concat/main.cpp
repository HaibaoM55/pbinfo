int concat(int a, int b){
	int c = a;
    int exp = 1;
    a = b;
    do{
        exp = exp*10;
        b = b/10;
    }while(b);
    c = c*exp+a;
    return c;
}
