void cifmaxmin(int n, int &vmax, int &vmin){
    if(n >= 10){
		cifmaxmin(n/10, vmax, vmin);
    }else{
    	vmax = 0;
        vmin = 9;
    }
    vmax = max(vmax, n%10);
    vmin = min(vmin, n%10);
}
