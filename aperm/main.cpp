#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;
ifstream fin("aperm.in");
ofstream fout("aperm.out");
int n, m;
int v[50004];
bool compara(str a, str b){
    if(strcmp(a.c, b.c) > 0){
        return true;
    }
    return false;
}
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x;
            fin >> x;

        }
    }
    sort(v+1, v+n+1, compara);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fout << v[i].c[j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
