int resturi(int n, int x, int y, int r)
{
    int nr = 0;
    if(x > y){
    	swap(x, y);
    }
    for(int i = r; i <= n; i += y){
        if(i % x == r){
            nr++;
 	    }
	}
    return nr;
}
