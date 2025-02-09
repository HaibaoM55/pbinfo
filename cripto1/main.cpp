#include <fstream>
#include <set>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("cripto1.in");
ofstream fout("cripto1.out");
int n, m, k, q;
char a[100005][13];
char bx[13];
int v[13];
char x[13];
set<long long> f;
long long b[100005];
int cuvmax = 0, cuvmaxi = 1;
int main()
{
    fin >> n >> m >> k >> q;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        long long h = 0;
        for(int l = k-1; l >= 0; l--){
            h = h*26+(a[i][l]-'a');
        }
        f.insert(h);
    }
    for(int i = 1; i <= m; i++){
        fin >> bx;
        long long h = 0;
        for(int l = k-1; l >= 0; l--){
            h = h*26+(bx[l]-'a');
        }
        b[i] = h;
    }
    for(int i = 1; i <= q; i++){
        int cuv = 0;
        for(int j = 0; j < k; j++){
            fin >> v[j];
        }
        long long val= 0;
        for(int l = k-1; l >= 0; l--){
            val = val*26+v[l];
        }
        for(int j = 1; j <= m; j++){
            if(f.find(val+b[j]) != f.end()){
                cuv++;
            }
        }
        if(cuv > cuvmax){
            cuvmax = cuv;
            cuvmaxi = i;
        }
    }
    fout << cuvmaxi << ' ' << cuvmax;
    return 0;
}
