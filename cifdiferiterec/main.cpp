int CifDiferiteRec(int x, int y){
    if(x < 10){
    	return (int) (x!=y);
    }else{
    	return (int)(x%10!=y)+CifDiferiteRec(x/10, y);
    }
}
