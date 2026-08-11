int ElimZTRec(int n){
    if(n < 10){
    	return n;
    }else{
        if(n % 10 == 0){
        	return ElimZTRec(n/10);
        }
        return n;
    }
}
