#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("posta.in");
ofstream fout("posta.out");
#define int long long
int n;
int v[100004];
signed main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int g = v[1]-1;
    for(int i = 2; i <= n; i++){
        g = __gcd(g, v[i]-v[i-1]);
    }
    fout << g;
    return 0;
}
