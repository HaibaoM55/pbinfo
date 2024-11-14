#include <fstream>
using namespace std;
ifstream fin("zmeu.in");
ofstream fout("zmeu.out");
long long n, m, a, b;
int main()
{
    fin >> n;
    fin >> m;
    a = n/(2*m);
    b = 2*m-(n%(2*m));
    fout << a << '\n';
    fout << b;
    return 0;
}
