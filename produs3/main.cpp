#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("produs3.in");
ofstream fout("produs3.out");
int n, x;
int f[10];
int exp(int n , int x)
{
    int c = 0;
    while(n % x == 0)
    {
        n /= x;
        c++;
    }
    return c;
}
int main()
{
    fin >> n;
    int c2=0, c3=0, c5=0;
    for(int i = 1; i <= n; i++){
        int x;
        fin >> x;
        c2 = (c2 + exp(x , 2)) % 2;
        c3 = (c3 + exp(x , 3)) % 2;
        c5 = (c5 + exp(x , 5)) % 2;
        f[4*c2 + 2*c3 + c5]++;
    }
    unsigned long long nr = f[0];
    for(int i = 0 ; i <= 10 ; i++){
        nr = nr + 1ll * f[i] * (f[i] - 1) / 2;
    }
    fout << nr;
    return 0;
}
