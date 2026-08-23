int UCP(int x){
	int n = -1;
    do{
        if(x%2 == 0){
        	n = x%10;
            return n;
        }
        x = x/10;
    }while(x);
    return n;
}
