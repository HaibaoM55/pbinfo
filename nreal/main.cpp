double nreal(int x, int y){
	double nr = x;
    int exp = 1;
    x = y;
    do{
        exp = exp*10;
        y = y/10;
    }while(y);
    double z = (1.0*x)/(1.0*exp);
    nr += z;
    return nr;
}
