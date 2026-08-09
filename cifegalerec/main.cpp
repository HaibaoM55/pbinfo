int CifEgaleRec(int x, int y){
    if(x < 10){
    	return (x==y);
    }else{
    	return (x%10==y) && CifEgaleRec(x/10, y);
    }
}
