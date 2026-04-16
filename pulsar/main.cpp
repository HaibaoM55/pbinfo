#include <fstream>
using namespace std;
ifstream fin("pulsar.in");
ofstream fout("pulsar.out");

int c, n, p;
struct pulsar{
    int x, y, r, t;
} pl[15001];
bool b[501][501];
int main(){
    fin >> c >> n >> p;
    for(int i = 1; i <= p; i++){
        fin >> pl[i].x >> pl[i].y >> pl[i].r >> pl[i].t;
    }
    int xs, ys, xf, yf;
    fin >> xs >> ys;
    fin >> xf >> yf;
    int smin = 2e9;
    for(int timp = 0; timp < 60; timp++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                b[i][j]=false;
            }
        }
        if(timp == 0){
            b[xs][ys] = true;
        }
        b[xf][yf] = true;
        for(int k = 1; k <= p; k++){
            int tmax = (pl[k].t+timp)%pl[k].r;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(abs(i - pl[k].x) + abs(j - pl[k].y) <= tmax){
                        b[i][j] = true;
                    }
                }
            }
        }
        int nr = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //fout << b[i][j] << ' ';
                if(!b[i][j]){
                    nr++;
                }
            }
            //fout<<'\n';
        }
        //fout<<'\n';
        if(nr < smin){
            smin = nr;
        }
    }
    fout << smin;
    return 0;
}
