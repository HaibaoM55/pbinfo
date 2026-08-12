int multiplu(int *v, int n, int k){
    if(n == 0){
    	return 0;
    }
    return (int)(v[n-1]%10==k&&v[n-1]%k==0)+multiplu(v, n-1, k);
}
