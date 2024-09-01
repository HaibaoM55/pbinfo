#include <iostream>

using namespace std;
int t,n,a,b,c,d;
int m[402][402];
long long v[402];
long long s[402][402];
long long x, nr = 0;
int main()
{
    cin >> t >> n >> a >> b >> c >> d;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            m[i][j] = (a * i + b * j + c) % d;
            s[i][j] = s[i-1][j]+m[i][j];
        }
    }
    for(int l1 = 1; l1 <= n; l1++){
        for(int l2 = l1; l2 <= n; l2++){
            for(int j = 1; j <= n; j++){
                v[j] = s[l2][j]-s[l1-1][j];
            }
            long long suma = 0;
            int j = 1;
            for(int i = 1; i <= n; i++){
                suma += v[i];
                while (suma > t){
                    suma -= v[j];
                    j++;
                }
                nr += i-j+1;
            }
        }
    }
    cout << nr;
    return 0;
}
