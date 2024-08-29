#include <iostream>
using namespace std;
int n, x;
int f[15];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int cif = 0;
        do{
            cif++;
            x = x/10;
        }while(x > 0);
        f[cif]++;
    }
    long long s = 0;
    for(int i = 1; i <= 10; i++){
        if(f[i] > 1){
            if(f[i] %2 == 0){
                long long p = f[i]/2;
                p = p * (f[i]-1);
                s += p;
            }else{
                long long p = (f[i]-1)/2;
                p = p*f[i];
                s += p;
            }
        }
    }
    cout << s;
    return 0;
}
