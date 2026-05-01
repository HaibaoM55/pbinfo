int FiboRec(int x, int y){
    if(x == 1 && y == 1){
    	return 1;
    }else if(x < 1){
    	return 0;
    }
    return FiboRec(y-x, x);
}
