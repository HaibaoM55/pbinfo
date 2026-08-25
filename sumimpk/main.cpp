int sub(int n, int v[], int k){
    int s = 0;
    for(int i = 0; i < n && k; i++){
        if(v[i] % 2 == 1){
        	k--;
            s += v[i];
        }
    }
    if(k) return -1;
	return s;
}
