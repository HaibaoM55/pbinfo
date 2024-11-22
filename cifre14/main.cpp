#include <fstream>
using namespace std;
ifstream cin("cifre.in");
ofstream cout("cifre.out");
int c, n;
long long nr = 0, x;
int f[12], v[12];
int nrap = 0;
int main()
{
    cin >> c >> n;
    if(c == 1){
        for(int i = 1; i <= n; i++){
            cin >> x;
            nr = 0;
            int z = 0;
            do{
                z++;
                v[z] = x%10;
                x = x/10;
            }while(x > 0);
            for(int j = z; j >= 1; j--){
                cout << v[j];
                if(v[j] % 2 == 0){
                    cout << v[j]/2;
                }
            }
            cout << ' ';
        }
    }else{
        long long nrmax = 0;
        for(int i = 1; i <= n; i++){
            cin >> x;
            for(int j = 0; j <= 9; j++){
                f[j] = 0;
            }
            int z = 0;
            do{
                z++;
                v[z] = x%10;
                x = x/10;
            }while(x > 0);
            for(int j = z; j >= 1; j--){
                f[v[j]]++;
                if(v[j] % 2 == 0){
                    f[v[j]/2]++;
                }
            }
            nr=0;
            for(int j = 0; j <= 9; j++){
                if(f[j] > 0){
                    nr = nr*10+f[j]%10;
                }
            }
            if(nr > nrmax){
                nrmax = nr;
                nrap = 1;
            }else if(nr == nrmax){
                nrap++;
            }
        }
        cout << nrmax << ' ' << nrap;
    }
    return 0;
}
