#define MODX 1000000007
#include <fstream>
using namespace std;
ifstream fin("easy_sum.in");
ofstream fout("easy_sum.out");
int n;
long long s;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        long long x;
        fin >> x;
        long long p = x*i;
        p = p % MODX;
        p = p*(n-i+1);
        p = p % MODX;
        s = s % MODX;
        s = s + p;
        s = s % MODX;
    }
    fout << s;
    return 0;
}
