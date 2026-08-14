bool verif(int a, int b, int n){
    return (1LL*a*b+a/b)==n;
}
void generatoare(int n){
    bool ok = false;
    for(int a = 2; a < n / 2;a += 2) {
        int b = n / a;
        if(a * b + a / b == n) {
            ok = true;
            cout << a << "-" << b << " ";
        }
    }
    if(n % 4 == 0){
    	cout << n/2 << '-' << 1;
    }
    if(!ok){
    	cout << "nu exista";
    }
}
