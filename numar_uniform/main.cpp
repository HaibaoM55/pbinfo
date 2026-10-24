int ImparPar(int n){
   int impar = 0, par = 0;
    do{
        if(n % 2 == 1){
            impar = impar*10+n%10;
        }else{
            par = par*10+n%10;
        }
        n = n/10;
    }while(n > 0);
    int rasp = 0;
    //cout << impar << ' ' << par;
    int i=0, p=0;
    int nrp = 1;
    do{
        i = i*10+impar%10;
        impar = impar/10;
    }while(impar);
    do{
        nrp = nrp*10;
        p = p*10+par%10;
        par = par/10;
    }while(par);
    return i*nrp+p;
}
