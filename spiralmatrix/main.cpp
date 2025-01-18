#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("spiralmatrix.in");
ofstream fout("spiralmatrix.out");
long long n;
int main()
{
    fin >> n;
    long long z1 = n;
    double sq2 = sqrt(2);
    z1 = ceil(n*(2-sq2)/4);
    long long aii = 1+4LL*(z1-1)*(n-z1+1);
    long long k1 = n*n;
    k1 = k1/2;
    long long k2 = k1+n%2+1;
    long long nre = n-2*(z1-1)-1;
    long long z = 0;
    int i1 = z1, j1 = z1;
    bool ok = true;
    if(aii+nre < k1){
        aii = aii + nre;
        j1 = n-z1+1;
    }else if(ok){
        j1 = j1+(k1-aii);
        aii = k1;
        ok = false;
        fout << i1 << ' ' << j1 << '\n';
    }
    if(aii+nre < k1){
        aii = aii + nre;
        i1 = n-z1+1;
    }else if(ok){
        i1 = i1+(k1-aii);
        aii = k1;
        ok = false;
        fout << i1 << ' ' << j1 << '\n';
    }
    if(aii+nre < k1){
        aii = aii + nre;
        j1 = z1;
    }else if(ok){
        j1 = j1-(k1-aii);
        aii = k1;
        ok = false;
        fout << i1 << ' ' << j1 << '\n';
    }
    if(ok){
        i1 = i1-(k1-aii);
        aii = k1;
        ok = false;
        fout << i1 << ' ' << j1 << '\n';
    }
    i1 = z1, j1 = z1;
    aii = 1+4LL*(z1-1)*(n-z1+1);
    ok = true;
    k1 = k2;
    if(aii+nre < k1){
        aii = aii + nre;
        j1 = n-z1+1;
    }else if(ok){
        j1 = j1+(k1-aii);
        aii = k1;
        ok = false;
        fout << i1 << ' ' << j1 << '\n';
    }
    if(aii+nre < k1){
        aii = aii + nre;
        i1 = n-z1+1;
    }else if(ok){
        i1 = i1+(k1-aii);
        aii = k1;
        ok = false;
        fout << i1 << ' ' << j1 << '\n';
    }
    if(aii+nre < k1){
        aii = aii + nre;
        j1 = z1;
    }else if(ok){
        j1 = j1-(k1-aii);
        aii = k1;
        ok = false;
        fout << i1 << ' ' << j1 << '\n';
    }
    if(ok){
        i1 = i1-(k1-aii);
        aii = k1;
        ok = false;
        fout << i1 << ' ' << j1 << '\n';
    }
    return 0;
}
