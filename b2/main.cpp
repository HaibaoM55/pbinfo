#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("b2.in");
ofstream fout("b2.out");
long long n, nr, nc;
bool b[64];
int main()
{
    fin >> nc;
    n = nc;
    while(n > 0){
        nr++;
        n = n/2;
    }
    for(int i = 1; i <= nr; i++){
        nr = 1LL*pow(2, i);
        for(int j = 0; j < i; j++){
            long long nr1 = 1LL*(nr+1LL*pow(2, j));
            if(nr1 > nc){
                return 0;
            }
            fout << nr1 << " ";
        }
    }
    return 0;
}
