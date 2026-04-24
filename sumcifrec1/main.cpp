void sumcif(int x, int &s){
    if(x == 0){
    	s = 0;
        return;
    }
    int p;
    sumcif(x/10, p);
    s = p+x%10;
}
