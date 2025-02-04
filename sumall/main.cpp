#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("sumall.in");
ofstream fout("sumall.out");
int n, cif;
char x[25];
unsigned long long l, s = 0;
long double p = 1;
int nr[53], f[12];
void inmultire(int a[], long double b)
{
    long long t = 0;
    for(int i = 1; i <= a[0]; i++){
        t += a[i] * b;
        a[i] = t % 10;
        t /= 10;
    }
    while(t > 0){
        a[0]++;
        a[a[0]] = t % 10;
        t /= 10;
    }
}
int main()
{
    fin >> x;
    l = strlen(x);
    for(int i = l-1; i >= 0; i--){
        nr[0]++;
        nr[nr[0]] = 1;
        p = p*(i + 1);
        f[x[i]-'0']++;
        p = p/f[x[i]-'0'];
        s += (x[i]-'0');
    }
    inmultire(nr, p * s / l);
    for(int i = nr[0]; i >= 1; i--){
        fout << nr[i];
    }
    return 0;
}
