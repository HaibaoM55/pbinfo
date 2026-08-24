bool eprim(int x){
	return x == 2 || x == 3 || x == 5 || x == 7;
}
int NrPrime(int n){
    int nr = 0;
    do{
        if(eprim(n%10)){
        	nr++;
        }
        n = n/10;
    }while(n);
    return nr;
}
