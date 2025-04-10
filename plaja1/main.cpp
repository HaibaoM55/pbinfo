#include <fstream>
using namespace std;
ifstream fin("plaja1.in");
ofstream fout("plaja1.out");
int a, b, u;
struct umbrela{
    int x, y;
}v[104];
int a1[2004][2004], s[2004][2004];
int n, m;
int main(){
    fin >> a >> b >> u;
    for(int i = 1; i <= u; i++){
        fin >> v[i].x >> v[i].y;
    }
    fin >> n;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        int x1,x2,y1,y2;
        fin >> x1 >> y1 >> x2 >> y2;
        a1[x1][y1]++;
        a1[x2+1][y1]--;
        a1[x1][y2+1]--;
        a1[x2+1][y2+1]++;
        bool ok = true;
        for(int j = 1; j <= u; j++){
            if(x1 <= v[j].x && v[j].x <= x2 && y1 <= v[j].y && v[j].y <= y2){
                ok = false;
                break;
            }
        }
        if(ok){
            nr++;
        }
    }
    fout << nr << ' ';
    nr = 0;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            a1[i][j] = a1[i-1][j]+a1[i][j-1]-a1[i-1][j-1]+a1[i][j];
            int x = 0;
            if(a1[i][j] >= 1){
                x = 1;
            }
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
        }
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        int x1,x2,y1,y2;
        fin >> x1 >> y1 >> x2 >> y2;
        bool ok = true;
        for(int j = 1; j <= u; j++){
            if(x1 <= v[j].x && v[j].x <= x2 && y1 <= v[j].y && v[j].y <= y2){
                ok = false;
                break;
            }
        }
        int suma = s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
        if(ok && suma == 0){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
