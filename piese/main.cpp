#include <iostream>
using namespace std;
int a[1040][1040];
int n;
int v = 0;
void nv(int l, int c, int d);
void sv(int l, int c, int d);
void se(int l, int c, int d);
void ne(int l, int c, int d);
void nv(int l, int c, int d){
    v++;
    if(d == 1){
        a[l][c+1] = v;
        a[l+1][c+1] = v;
        a[l+1][c] = v;
    }else{
        int lg = (1 << (d/2));
        sv(l, c+lg, d/2);
        nv(l+lg, c+lg, d/2);
        ne(l+lg, c, d/2);
        a[l+lg-1][c+lg]=v;
        a[l+lg][c+lg]=v;
        a[l+lg][c+lg-1]=v;
        nv(l, c, d/2);
    }
}
int main()
{
    cin >> n;

    return 0;
}
