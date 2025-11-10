#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cioc.in");
ofstream fout("cioc.out");
int c, n, k;
long long a[100004];
struct maimamcaindahomles{
    long long x;
    int i;
}v[100004];
bool compara(maimamcaindahomles a, maimamcaindahomles b){
    if(a.x < b.x){
        return true;
    }
    return false;
}
int p = 0;
int fr[100004];
int main(){
    fin >> c >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        v[i].i = i;
        v[i].x = a[i];
    }
    sort(v+1, v+n+1, compara);
    int k_final = 0;
    for(int i = 1; i <= n; i++){
        if(p < k){
            fr[v[i].i] = 1;
            p++;
            k_final++;
        }else if(p == k && v[i].x == v[i-1].x){
            fr[v[i].i] = 1;
            k_final++;
        }else{
            break;
        }
    }
    if(c == 1){
        fout << k_final;
    }else{
        for(int i = 1; i <= n; i++){
            fout << a[i] << " ";
            if(fr[i]){
                fout << (a[i]*2LL) << " ";
            }
        }
    }
    return 0;
}
