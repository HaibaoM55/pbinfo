#include <fstream>
#include <algorithm>
using namespace std;
#pragma GCC optimize("O1")
ifstream fin("livada1.in");
ofstream fout("livada1.out");
int n, m, r;
long long c;
int x, y, z, w, u;
long long a[104][25004];
long long vmax[104][25004], sp[104][25004];
long long s[104];
long long sma(long long val){
    for (int i=1;i<=n;i++){
        int p1 = 1, p2 = m, p = 0;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(vmax[i][mij] <= val){
                p1 = mij+1;
                p = mij;
            }else{
                p2 = mij-1;
            }
        }
        s[i] = sp[i][p];
    }
    sort(s+1, s+n+1);
    long long sms=0;
    for(int i = n; i >= n-r+1;i--){
        sms += s[i];
    }
    return sms;
}
int main(){
    fin >> n >> m >> c >> r;
    fin >> x >> y >> z >> w >> u;
    for(int i = 1; i <= m; i++){
        fin >> a[1][i];
    }
    for(int i = 2; i <= n; i++){
        fin >> a[i][1];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            a[i][j] = (x*a[i-1][j] + y*a[i][j-1] + z*a[i-1][j-1] + w) % u;
        }
    }
    for(int i = 1; i <= n;i++){
        sp[i][0] = 0;
        vmax[i][0] = 0;
        for(int j = 1; j <= m; j++){
            sp[i][j] = sp[i][j-1]+a[i][j];
            vmax[i][j] = max(vmax[i][j-1], a[i][j]);
        }
    }
    long long p1 = 1, p2 = c, p = 0;
    while(p1 <= p2){
        long long mij = (p1+p2)/2;
        if(sma(mij) < c){
            p1 = mij+1;
        }else{
            p2 = mij-1;
            p = mij;
        }
    }
    fout << p;
    return 0;
}
