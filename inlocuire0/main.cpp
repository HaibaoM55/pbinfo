void num(int n, int a[]){
    for(int i = n-1; i >= 0; i--){
        if(a[i] <= a[0]){
        	a[i] = 0;
        }
    }
}
