void identice(int a, int b){
    bool exista = false;
    for(int i = a; i <= b; i++){
    	int x = i;
        bool ok = true;
        do{
            if(x%10 != i%10){
            	ok = false;
            }
            x = x/10;
        }while(x > 0);
        if(ok){
     		exista = true;
            cout << i << ' ';
        }
    }
    if(!exista){
    	cout <<"nu exista";
    }
}
