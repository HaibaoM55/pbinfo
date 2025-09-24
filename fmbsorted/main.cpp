int FMBSorted(int a[2001][2001], int n){
    //busy forever
    int nrmax = 0;
    for(int i = 1; i <= n; i++){
        int p1 = 1, p2 = n, p = n+1;
        if(a[i][n-nrmax] == 1){
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(a[i][mij] == 1){
                    p = mij;
                    p2 = mij-1;
                }else{
                    p1 = mij+1;
                }
            }
        }
        nrmax = max(nrmax, n-p+1);
    }
    return nrmax;
}
