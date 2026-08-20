void ordon123(int n, int a[]){
	int f1=0, f2=0, f3=0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
        	f1++;
        }else if(a[i] == 2){
        	f2++;
        }else{
            f3++;
        }
    }
    int z = 0;
    while(f1){
    	f1--;
        a[z] = 1;
        z++;
    }
    while(f2){
    	f2--;
        a[z] = 2;
        z++;
    }
    while(f3){
    	f3--;
        a[z] = 3;
        z++;
    }
}
