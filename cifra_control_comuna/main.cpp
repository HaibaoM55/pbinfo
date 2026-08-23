int cifcontrol(int x){
    if(x % 9 == 0){
    	return 9;
    }
    return x%9;
}
int sum_cifra_control(int a, int b){
    int nr = 0;
    for(int i = 1; i <= b; i++){
        if(cifcontrol(i) == a){
        	nr++;
        }
    }
    return nr;
}
