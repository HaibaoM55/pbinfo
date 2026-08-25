void Succesor(int a[], int n, int k){
    for(int i = k; i >= 1; i--){
    	int ult = a[i]+1+(k-i);
        if(ult <= n){
            a[i]++;
            for(int j = i+1; j <= k; j++){
            	a[j] = a[j-1]+1;
            }
            return;
        }
    }
}
