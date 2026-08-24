int multipli(int a, int b, int c){
    int nr = b/c-a/c;
    if(a % c == 0){
    	nr++;
    }
    return nr;
}
