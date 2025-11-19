int FAlternant(int a[], int n){
    if(n == 1){
        return 1;
    }else{
        if(n % 2 == 1){
            if(a[n] % 2 == a[1] % 2){
                return FAlternant(a, n-1);
            }else{
                return 0;
            }
        }else{
            if(a[n] % 2 != a[1] % 2){
                return FAlternant(a, n-1);
            }else{
                return 0;
            }
        }
    }
}
