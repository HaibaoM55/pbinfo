void sterge(int v[], int &n, int i, int j){
	int y = j+1;
    for(int x = i; x <= n; x++){
		v[x] = v[y];
        y++;
        if(y == n+1){
        	break;
        }
    }
    n -= j-i+1;
}
