int nr_vocale(char x[]){
    if(x[0] == 0){
    	return 0;
    }
    int nr = 0;
    if('A' <= x[0] && x[0] <= 'Z'){
        x[0] = x[0]-'A'+'a';
    }
    if(x[0] == 'a' || x[0] == 'e' || x[0] == 'i' || x[0] == 'o' || x[0] == 'u'){
    	nr++;
    }
    return nr+nr_vocale(x+1);
}
