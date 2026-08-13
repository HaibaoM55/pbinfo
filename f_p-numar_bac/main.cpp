bool estepnumar(int x){
	int suma = 0;
    for(int i = 1; i*i <= x; i++){
        if(x % i == 0){
        	suma += i;
            if(i*i < x){
            	suma += x/i;
            }
        }
    }
    return suma%2==x%2;
}
int kpn(int a, int b, int k){
    for(int i = a; i <= b; i++){
        if(estepnumar(i)){
        	k--;
        }
        if(k == 0){
        	return i;
        }
    }
    return -1;
}
