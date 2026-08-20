void teren(int x, int y){
	int a = x*y;
    bool ok = false;
    for(int i = 2; i*i <= a; i += 2){
        if(a % i == 0){
        	cout << i << " parcele de arie " << a/i << '\n';
        	ok = true;
        }
    }
    if(!ok){
    	cout << "nu exista";
    }
}
