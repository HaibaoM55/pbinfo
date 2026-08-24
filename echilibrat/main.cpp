int echilibrat(int n){
	int s1=0, s2=0;
    int nrcif = 0;
    bool unu = true;
    do{
        if(unu){
        	s1 += n%10;
        }else{
            s2 += n%10;
        }
		unu = !unu;
    	nrcif++;
        n = n/10;
    }while(n);
    if(s1%2== 0&& s2%2 ==1){
    	return 1;
    }
    return 0;
}
