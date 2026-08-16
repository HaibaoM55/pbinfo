void P(int x[], int n, int &mini, int &maxi, int &sum){
    mini = 2e9, maxi = 0, sum=0;
    for(int i = 0; i < n; i++){
    	sum += x[i];
        mini = min(mini, x[i]);
        maxi = max(maxi, x[i]);
    }
}
