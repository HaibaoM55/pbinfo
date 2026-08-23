int TreiCifImp(int x){
    while(x >= 100){
        if(x%2 == (x/10)%2 && x%2 == (x/100)%2 && x%2==1){
        	return 1;
        }
        x = x/10;
    }
    return 0;
}
