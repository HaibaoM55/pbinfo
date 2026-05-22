int PDoi(int n){
    if(n == 1){
    	return 1;
    }
    if(n % 2 == 0){
    	return PDoi(n/2);
    }else{
     	return 0;
    }
}
