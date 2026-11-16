void depozit(int x, int y, int z, int &n){
    for(int i = 1; i <= 1000000; i++){
        if(i % x == 0 && i % y == 0 && i % z == 0){
            n = i;
            return;
        }
    }
}
