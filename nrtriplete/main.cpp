long long NrTriplete(int a[], int n, int S){
    sort(a, a+n);
    long long suma = 0;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            int p1 = j+1, p2 = n-1, p = j;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(a[i]+a[j]+a[mij] >= S){
                    p2 = mij-1;
                }else{
                    p = mij;
                    p1 = mij+1;
                }
            }
            suma += p-j;
        }
    }
    return suma;
}
