void MatImp(int a[100][100], int n, int L[], int &k){
    k = 0;
    for(int i = 0; i < n; i++){
        int nrp = 0, nri = 0;
        for(int j = 0; j < n; j++){
            if(a[i][j] % 2 == 0){
                nrp++;
            }else{
                nri++;
            }
        }
        if(nri > nrp){
            L[k] = i;
            k++;
        }
    }
}
