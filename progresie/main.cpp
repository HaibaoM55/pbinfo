#include <fstream>
#include <bitset>
using namespace std;
#pragma GCC optimize("O1")
ifstream fin("progresie.in");
ofstream fout("progresie.out");
int n;
int v[40004];
int z = 0;
int main()
{
    fin >> n;
    v[0] = 1;
    for(int i = 0; i <= n; i++){
        v[2*i] = 3*v[i]-2;
        v[2*i+1]= 3*v[i]-1;
    }
    for(int i = 1; i <= n; i++){
        fout << v[i] << ' ';
    }
    return 0;
}
