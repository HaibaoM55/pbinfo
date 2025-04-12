#include <fstream>
using namespace std;
#define int long long
ifstream fin("pietricele.in");
ofstream fout("pietricele.out");
int c, n, k;
char p[200004];
int v[200004];
int val[26];
long long s[200004];
bool sumamin(long long j){
    long long suma = 0;
    int nrp = 0;
    for(int i = 1; i <= n; i++){
        suma += v[i];
        if(suma >= j){
            suma = 0;
            nrp++;
        }
    }
    if(nrp < k){
        return false;
    }
    return true;
}
signed main(){
    fin >> c >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> p[i];
    }
    for(int i = 0; i <= 25; i++){
        fin >> val[i];
    }
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        v[i] = val[p[i]-'a'];
        s[i] = s[i-1]+v[i];
    }
    if(c == 1){
        int lg = n-k+1;
        long long smax = 0;
        for(int i = 1; i <= n-lg+1; i++){
            int j = i+lg-1;
            long long suma = s[j]-s[i-1];
            if(suma > smax){
                smax = suma;
            }
        }
        fout << smax;
    }else{
        bool toateegale = true;
        for(int i = 0; i <= n; i++){
            if(v[i] != v[i+1]){
                toateegale = false;
                break;
            }
        }
        if(toateegale){
            long long rez = v[1];
            rez = rez*(n/k);
            fout << rez;
        }
        long long p1 = 1, p2 = 2e14, poz;
        while(p1 <= p2){
            long long mij = p1+p2;
            mij = mij/2;
            if(sumamin(mij)){
                poz = mij;
                p1 = mij+1;
            }else{
                p2 = mij-1;
            }
        }
        fout << poz;
    }
    return 0;
}
