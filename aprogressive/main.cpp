#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("aprogressive.in");
ofstream fout("aprogressive.out");
int c;
int n, m;
int a[1028][1028];
long long s[1028];
long long sl[1028][1028];
int v[1028];
int ratie(int x1, int y1, int x2, int y2){
    v[0] = 0;
    if(x1 == x2 || y1 == y2){
        return 0;
    }
    for(int i = x1; i <= x2; i++){
        v[0]++;
        v[v[0]] = sl[i][y2]-sl[i][y1-1];
    }
    if(v[0] == 1){
        return 0;
    }
    sort(v+1, v+v[0]+1);
    int r = v[2]-v[1];
    if(r == 0){
        return -1;
    }
    for(int i = 2; i <= v[0]; i++){
        if(v[i]-v[i-1] != r){
            return -1;
        }
    }
    return r;
}
void rezolva(int x1, int y1, int x2, int y2){
    int r = ratie(x1, y1, x2, y2);
    if(r == -1){
        fout << '(';
        rezolva(x1, y1, (x1+x2)/2, (y1+y2)/2);
        rezolva(x1, (y1+y2)/2+1, (x1+x2)/2, y2);
        rezolva((x1+x2)/2+1, y1, x2, (y1+y2)/2);
        rezolva((x1+x2)/2+1, (y1+y2)/2+1, x2, y2);
        fout << ')';
    }else{
        fout << '(' << x1 << ',' << y1 << ',' << x2 << ',' << y2 << ',' << r << ')';
    }
}
int main(){
    fin >> c;
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        sl[i][0] = 0;
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            s[i] += a[i][j];
            sl[i][j] = sl[i][j-1]+a[i][j];
        }
    }
    if(c == 1){
        long long vmax = 0;
        for(int i = 1; i <= n; i++){
            if(s[i] > vmax){
                vmax = s[i];
                v[0] = 1;
                v[1] = i;
            }else if(s[i] == vmax){
                v[0]++;
                v[v[0]] = i;
            }
        }
        for(int i = 1; i <= v[0]; i++){
            fout << v[i] << '\n';
        }
    }else if(c == 2){
        for(int i = 1; i <= n; i++){
            sort(a[i]+1, a[i]+m+1);
            bool ok = true;
            for(int j = 2; j < m; j++){
                if(a[i][j+1]-a[i][j] != a[i][j]-a[i][j-1]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                fout << i << '\n';
            }
        }
    }else{
        rezolva(1, 1, n, m);
    }
    return 0;
}
