void FMatrixCol(int a[50][50], int n, int m){
    for(int j = 0; j < m; j++){
        int vmin = 2e9, vmini = -1;
        for(int i = 0; i < n; i++){
            if(a[i][j] < vmin){
                vmin = a[i][j];
                vmini = i;
            }
        }
        if(vmin % 2 == 0){
            swap(a[vmini][j], a[0][j]);
        }else{
            swap(a[vmini][j], a[n-1][j]);
        }
    }
}
