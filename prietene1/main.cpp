#include <fstream>
using namespace std;
ifstream fin("prietene.in");
ofstream fout("prietene.out");
int c;
int n, m;
int a[10004], b[10004];
int dmax = 0, dmaxi = 0;
bool ciur[35004];
int nrp = 0;
int prm[35004];
int fa[10004], fb[10004];
int nrdiv(int x){
    int div = 0;
    for(int i = 1; i <= nrp && prm[i] <= x; i++){
        if(x % prm[i] == 0){
            div++;
        }
    }
    if(div == 0){
        return 1;
    }
    return div;
}
int main()
{
    fin >> c;
    fin >> n >> m;
    for(int i = 2; i <= 35000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j*i <= 35000; j++){
                ciur[j*i] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> b[i];
    }
    if(c == 1){
        for(int i = 1; i <= n; i++){
            int nr = nrdiv(a[i]);
            if(nr > dmax){
                dmax = nr;
                dmaxi = a[i];
            }else if(nr == dmax && a[i] > dmaxi){
                dmaxi = a[i];
            }
        }
        for(int i = 1; i <= m; i++){
            int nr = nrdiv(b[i]);
            if(nr > dmax){
                dmax = nr;
                dmaxi = b[i];
            }else if(nr == dmax && b[i] > dmaxi){
                dmaxi = b[i];
            }
        }
        fout << dmaxi;
    }else{
        for(int i = 1; i <= n; i++){
            fa[nrdiv(a[i])]++;
        }
        for(int i = 1; i <= m; i++){
            fb[nrdiv(b[i])]++;
        }
        long long s = 0;
        for(int i = 1; i <= 1000; i++){
            s = s + 1LL*fa[i]*fb[i];
        }
        fout << s;
    }
    return 0;
}
