#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("genpascal.in");
ofstream fout("genpascal.out");
int n, m;
int l;
int s[2001];
int p[4];
void prod(int a[], int b) {
    int t = 0;
    for(int i = 1; i <= a[0]; i++) {
        a[i] = a[i] * b + t;
        t = a[i] / 10;
        a[i] = a[i] % 10;
    }

    while(t != 0) {
        a[0]++;
        a[a[0]] = t % 10;
        t /= 10;
    }
}
void atr(int a[], int b[]) {
    a[0] = b[0];
    for(int i = 1; i <= a[0]; i++) {
        a[i] = b[i];
    }
}
int main()
{
    fin >> n >> m;
    fin >> l;
    int x = n+m;
    int nr = 0;
    do{
        nr++;
        p[nr] = x%10;
        x = x/10;
    }while(x > 0);
    p[0] = nr;
    atr(s, p);
    /*
    3   n+m
    6   2(n+m)
    12  4(n+m)
    24  8(n+m)
    48  16(n+m)
    96  32(n+m)
    ...
    */
    for(int i = 2; i <= l-1; i++){
        prod(s, 2);
    }
    for(int i = s[0]; i >= 1; i--){
        fout << s[i];
    }
    return 0;
}
