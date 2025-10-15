bool esteprim(int x){
    for(int i =  2; i*i <= x; i++){
        if(x % i == 0){
        	return false;
        }
    }
	return true;
}
void afisare(int a, int b){
    if(a > b){
    	swap(a, b);
    }
    for(int i = a; i <= b; i++){
        if(esteprim(i)){
        	cout << i << ' ';
        }
    }
}
