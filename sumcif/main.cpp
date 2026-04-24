int sumcif(int x){
    if(x == 0){
    	return 0;
    }
	return x%10+sumcif(x/10);
}
