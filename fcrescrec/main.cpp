int FCrescRec(int n){
    if(n < 10){
    	return 1;
    }else if(n < 100){
    	return n%10 <= n/10;
    }else{
     	return n%10 <= n/10%10 &&   FCrescRec(n/10);
    }
}
