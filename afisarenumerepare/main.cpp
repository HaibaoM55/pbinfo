void afisare(int a, int b){
    for(int i = min(a, b); i <= max(a, b); i++){
        if(i % 2 == 0){
        	cout << i << ' ';
        }
    }
}
