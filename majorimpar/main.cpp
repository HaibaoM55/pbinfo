bool estemajimp(int x){
	int sp = 0, si = 0;
    for(int d = 2; d*d <= x; d++){
        if(x % d == 0){
            if(d % 2 == 0){
            	sp += d;
            }else{
                si += d;
            }
            if(d*d < x){
                if((x/d)%2==0){
                	sp += x/d;
                }else{
                    si += x/d;
                }
            }
        }
    }
    return si > sp;
}
int majImp(int a, int b){
    for(int i = a; i <= b; i++){
        if(estemajimp(i)){
        	return i;
        }
    }
    return 0;
}
