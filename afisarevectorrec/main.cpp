void afisvec(int *v, int n, int i = 0){
	cout << v[i] << ' ';
    if(n-1 > i){
    	afisvec(v, n, i+1);
    }
}
