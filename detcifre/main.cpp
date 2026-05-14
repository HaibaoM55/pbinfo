void detcifre(int n, int &p, int &u){
	u = n%10;
    do{
        p = n%10;
        n = n/10;
    }while(n);
}
