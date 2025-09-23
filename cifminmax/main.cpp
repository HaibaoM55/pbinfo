void cifminmax(int n, int &cifmax, int &cifmin){
	int x = n;
    cifmax = 0,cifmin = 10;
    do{
        cifmax = max(cifmax, x%10);
        cifmin = min(cifmin, x%10);
        x = x/10;
    }while(x > 0);
}
