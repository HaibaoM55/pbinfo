int ascendent(int n, int x, int y){
    int s = 0;
    for(int i = x; i <= y; i++){
    	int p = i;
        bool ok = true;
        do{
            if(p%10 < n%10){
            	ok = false;
            }
            p = p/10;
        }while(p);
        if(ok){
        	s += i;
        }
    }
    return s;
}
