void produsmaxim(int n, int &pmax, int &st, int &dr){
	pmax = -1;
    st = n, dr = 0;
    int st1 = n, dr1 = 0, exp = 1;
    while(st1 > 0){
        dr1 = exp*(st1%10)+dr1;
        exp = exp*10;
    	st1 = st1/10;
        if(dr1*st1 > pmax){
        	pmax = dr1*st1;
            st = st1;
            dr = dr1;
        }
    }
}
