#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("mozaic.in");
ofstream fout("mozaic.out");
long long a, b;
long long nr, nrx;
int main()
{
    fin >> a >> b;
    long long g = __gcd(a, b);
    nr = g;
    nr = nr*nr;
    nr = 2*nr;
    long long arie = a*b;
    long double arie2 = ((double)g*g/2);
    nrx = arie/arie2;
    fout << nr << ' ' << nrx;
    return 0;
}
