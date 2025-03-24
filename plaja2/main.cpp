#include <fstream>
using namespace std;
ifstream fin("plaja2.in");
ofstream fout("plaja2.out");
long long n, k, t;
long long z1, t1;
long long zn, tn;
int main()
{
    fin >> n >> k >> t;
    fin >> z1 >> t1;
    long long r = t1 + t * (z1 - 1);
    for(long long i = 2; i <= k; i++){
        fin >> zn >> tn;
        long long z = (tn-t1 + z1*t + zn*t)/(2*t);
        r = max(r, (z-z1)*t+t1);
        r = max(r, (zn-z-1)*t+tn);
        z1 = zn;
        t1 = tn;
    }
    r = max(r, 1LL*(n - z1) * t + t1);
    fout << r;
    return 0;
}
