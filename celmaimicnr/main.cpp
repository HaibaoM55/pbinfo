int cmmnr(int x){
    int f[12] = {0,0,0,0,0,0,0,0,0,0};
    int n = 0;
    do{
        f[x%10]++;
        x = x/10;
    }while(x);
    for(int i = 1; i <= 9; i++){
        if(f[i]){
			n = n*10+i;
    		f[i]--;
        	break;
        }
    }
    while(f[0]){
    	f[0]--;
        n = n*10;
    }

    for(int i = 1; i <= 9; i++){
        while(f[i]){
			n = n*10+i;
    		f[i]--;
        }
    }
    return n;
}
