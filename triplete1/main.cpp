void triplete(int n){
    //x*y+y*z=n
    //y*(x+z)=n
    for(int y = 1; y <= n; y++){
        if(n % y == 0){
            for(int x = 0; x < y; x++){
                int z = n/y;
                z -= x;
                if(x < y && y < z){
                    cout << "(";
                    cout << x << ","<<y<<","<<z<<")\n";
                }
            }
        }
    }
}
