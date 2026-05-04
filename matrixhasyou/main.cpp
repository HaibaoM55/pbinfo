void Matrix(int a[300][300], int n, int L[], int C[], int k){
    bool lin[304], col[304];
    for(int i = 0; i < n; i++){
    	lin[i] = false;
        col[i] = false;
    }
    for(int z = 0; z < k; z++){
        for(int j = 0; j < n; j++){
			a[L[z]][j]++;
        }
        for(int i = 0; i < n; i++){
        	a[i][C[z]]++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = a[i][j]%2;
        }
    }
}
