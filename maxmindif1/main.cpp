int MaxMinDif1(int a[], int n){
	int f[20004];
    for(int i = 0; i <= 20000; i++){
    	f[i] = 0;
    }
    for(int i = 0; i < n; i++){
    	f[a[i]+10000]++;
    }
    int rasp = 0;
    for(int i = 0; i < 20000; i++){
    	rasp = max(rasp, f[i]+f[i+1]);
    }
    return rasp;
}
