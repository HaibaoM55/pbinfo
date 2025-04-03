#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
ifstream fin("prosum.in");
ofstream fout("prosum.out");
long long n;
map<long long, int> f;
long long v[100004];
long long m;
long long d, x, y;
void euclid(long long a, long long b, long long &d, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    long long x0, y0;
    euclid(b, a % b, d, x0, y0);
    x = y0;
    y = x0 - (a / b) * y0;
}
int main()
{
    fin >> n >> m;
    long long nr = 0;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    sort(v+1, v+n+1);
    for(int i = 1; i <= n; i++){
        long long a = v[i];
        euclid(a+1, m, d, x, y);
        if (d == 1) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            nr += f[x];
        }
        f[(a+1)%m]++;
    }
    fout << nr;
    return 0;
}
