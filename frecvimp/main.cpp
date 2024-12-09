#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("frecvimp.in");
ofstream fout("frecvimp.out");
int n;
int f[65];
long long x;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if((x & (x-1)) == 0){
            int j = log2(x);
            f[j]++;
        }
    }
    long long nr = 1;
    for(int i = 0; i <= 64; i++){
        if(f[i] % 2 != 0){
            fout << nr;
            break;
        }
        nr = nr*2;
    }
    return 0;
}
