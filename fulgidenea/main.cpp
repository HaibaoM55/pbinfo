int Fulg(int n){
    int f[14];
    for(int i = 0; i < 10; i++){
    	f[i] = 0;
    }
    int x = 0;
    do{
        x++;
        f[n%10]++;
        if(n%10 == 0 || n%10 > 4){
        	return 0;
        }
        n = n/10;
    }while(n);
    if(x == 9 && f[1] && f[2] && f[3] && f[4]){
    	return 1;
    }
    return 0;
}
