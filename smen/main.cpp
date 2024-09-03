#include <fstream>
using namespace std;
ifstream fin("smen.in");
ofstream fout("smen.out");
long long n, pv = 3;
int main()
{
    fin >> n;
    for(int i = 2; i <= n; i++){
        pv = (pv*pv/(i+2)+pv*i+i+1)%666013;
    }
    fout << pv;
    return 0;
}
