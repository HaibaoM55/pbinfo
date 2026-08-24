int DivImpar(int a, int b){
    int vmax = 1;
    for(int d = 2; d*d <= a; d++){
        if(a % d == 0){
            if(b % d == 0 && d % 2 == 1){
                vmax = max(vmax, d);
            }
            if(d*d < a){
                if(b % (a/d) == 0 && (a/d)%2 == 1){
                    vmax = max(vmax, a/d);
                }
            }
        }
    }
    return vmax;
}
