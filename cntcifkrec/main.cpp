void cnt_cif(int n, int k, int &c){
    c = 0;
    do{
        if(n%10 >= k){
            c++;
        }
        n = n/10;
    }while(n);
}
