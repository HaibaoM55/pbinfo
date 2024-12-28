#include <fstream>
#include <climits>
using namespace std;
ifstream fin("abx.in");
ofstream fout("abx.out");
int n;
long long m, x;
long long putere(long long a, long long b){
    long long r = 1;
    for(long long i = 1; i <= b; i++){
        if(r > LLONG_MAX/a){
            return LLONG_MAX;
        }else{
            r = r*a;
        }
    }
    return r;
}
long long nr(long long x, long long n) {
    long long p1 = 1, p2 = x, mij;
    while(p1 < p2){
        mij = (p1 + p2 + 1) / 2;
        if (putere(mij, n) <= x) {
            p1 = mij;
        } else {
            p2 = mij - 1;
        }
    }
    return p1;
}
long long nrc(long long x, long long n){
    long long p1 = 1, p2 = x, mij;
    while(p1 < p2) {
        mij = (p1 + p2) / 2;
        if(putere(mij, n) < x) {
            p1 = mij + 1;
        }else{
            p2 = mij;
        }
    }
    return p1;
}
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> x;
        long long rp = 0, vmin = LLONG_MAX;
        for(int j = 2; j <= 60; j++){
            long long l, u;
            l = nr(x, j);
            u = nrc(x, j);
            long long lp = putere(l, j);
            long long up = putere(u, j);
            if(x - lp <= vmin && lp <= m) {
                vmin = x - lp;
                rp = lp;
            }
            if(up - x < vmin && up<= m) {
                vmin = up - x;
                rp = up;
            }
        }
        fout << rp << '\n';
    }
    return 0;
}
