int Egal(int n){
    int cif = -1;
    do{
        if(n%2 == 1){
            if(cif == -1){
            	cif = n%10;
            }else if(n%10 != cif){
            	return 0;
            }
        }
        n = n/10;
    }while(n);
    return 1;
}
