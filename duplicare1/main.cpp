void duplicare(int n, int &d){
    int exp = 1;
    d = 0;
    bool ok = false;
    while(n){
        d += exp*(n%10);
        exp = exp*10;
        if(n % 2 == 0){
        	d += exp*(n%10);
        	exp = exp*10;
        	ok = true;
        }
        n = n/10;
    }
    if(!ok) d = -1;
}
