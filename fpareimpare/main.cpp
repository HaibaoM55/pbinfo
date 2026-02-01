int FPareImpare(int n){
    int f[5] = {0,0};
    do{
       	f[n%2]++;
        n = n/10;
    }while(n > 0);
    if(f[0] == f[1]){
        return 0;
    }else{
		return 1;
    }
}
