int numarare(int *v, int n){
    if(n == 0){
    	return 0;
    }
    return (int)(v[n-1]==v[n-2])+numarare(v, n-1);
}
