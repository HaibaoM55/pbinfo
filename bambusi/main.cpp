#include <fstream>
using namespace std;
#define int long long
ifstream fin("bambusi.in");
ofstream fout("bambusi.out");
int n, k;
int v[100004];
int suma(int bubu){
    int s = 0;
    for(int i = 1; i <= n; i++){
        s += max(v[i]-bubu, 0LL);
    }
    return s;
}
signed main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int p1 = 1, p2 = 1000000000, p = 0;
    while(p1 <= p2){
        int mij = (p1+p2)/2;
        if(suma(mij) < k){
            p2 = mij-1;
        }else{
            p = mij;
            p1 = mij+1;
        }
    }
    fout << p;
    return 0;
}
