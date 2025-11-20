int F23(int n){
    if(n == 1){
        return 1;
    }
    if(n % 2 == 0){
        F23(n/2);
    }else if(n % 3 == 0){
        F23(n/3);
    }else{
        return 0;
    }
}
