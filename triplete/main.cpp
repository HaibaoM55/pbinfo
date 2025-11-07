void triplete(int a, int b, int c){
    bool ok = false;
    for(int x = a; x <= b; x++){
        for(int y = x; y <= b; y++){
        	int z = c-x-y;
            if(z >= y){
                if(a <= z && z <= b){
                    ok = true;
                    cout << '{'<<x<<','<<y<<','<<z<<'}'<<'\n';
                }
            }else{
             	break;
            }
        }
    }
    if(!ok){
    	cout << "nu exista";
    }
}
